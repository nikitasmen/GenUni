class QueryGenerator:
    def __init__(self, table_name):
        self.query = ""
        self.table_name = table_name 

    def select(self, columns=None, options=None):
        self.query = "SELECT "  
        if options and isinstance(options, dict):
            for func_name, args in options.items():
                if func_name in functions:
                    if isinstance(args, (list, tuple)):
                        functions[func_name](self, *args)
                    else:
                        functions[func_name](self, args)
        if columns:
            # Handle subquery in columns
            processed_columns = []
            for col in columns:
                if isinstance(col, QueryGenerator):
                    processed_columns.append(f"({col.build(include_semicolon=False)})")
                else:
                    processed_columns.append(col)
            columns = ", ".join(processed_columns)
        else:
            columns = "*"
        self.query += f"{columns}"
        return self

    def where(self, conditions, operator="AND"):
        if not conditions:
            return self
            
        conditions_list = []
        for col, val in conditions.items():
            if isinstance(val, QueryGenerator):
                # Handle subquery value
                subquery = val.build(include_semicolon=False)
                conditions_list.append(f"{col} = ({subquery})")
            elif isinstance(val, list) and len(val) > 0 and all(isinstance(x, str) for x in val):
                # Handle IN clause with list of values
                values_str = ", ".join([f"'{x}'" for x in val])
                conditions_list.append(f"{col} IN ({values_str})")
            elif val is None:
                conditions_list.append(f"{col} IS NULL")
            else:
                conditions_list.append(f"{col} = '{val}'")
                
        condition_str = f" {operator} ".join(conditions_list)
        self.query += f" WHERE {condition_str}"
        return self

    def from_table(self, table_name=None):   
        if table_name:
            if isinstance(table_name, QueryGenerator):
                self.query += f" FROM ({table_name.build(include_semicolon=False)})"
                return self
            self.table_name = table_name
        self.query += f" FROM {self.table_name}"
        return self
    
    def insert(self, data):
        keys = list(data.keys())
        values = []
        
        for key, value in data.items():
            if isinstance(value, QueryGenerator):
                # Handle QueryGenerator object as subquery
                values.append(f"({value.build(include_semicolon=False)})")
            elif isinstance(value, str) and value.startswith('(') and value.endswith(')'):
                values.append(value)  # Don't wrap subqueries in quotes
            else:
                values.append(f"'{value}'")
        
        self.query = f"INSERT INTO {self.table_name} ({', '.join(keys)}) VALUES ({', '.join(values)})"
        return self
 
    def group_by(self, columns):
        if isinstance(columns, list):
            columns = ", ".join(columns)
        self.query += f" GROUP BY {columns}"
        return self
    
    def having(self, condition):
        # Support for subquery in HAVING clause
        if isinstance(condition, QueryGenerator):
            subquery = condition.build(include_semicolon=False)
            self.query += f" HAVING ({subquery})"
        else:
            self.query += f" HAVING {condition}"
        return self

    def update(self, data):
        update_parts = []
        for key, value in data.items():
            if isinstance(value, QueryGenerator):
                # Handle QueryGenerator object as subquery
                update_parts.append(f"{key} = ({value.build(include_semicolon=False)})")
            elif isinstance(value, str) and value.startswith('(') and value.endswith(')'):
                update_parts.append(f"{key} = {value}")
            else:
                update_parts.append(f"{key} = '{value}'")
        
        self.query = f"UPDATE {self.table_name} SET {', '.join(update_parts)}"
        return self

    def delete(self):
        self.query = f"DELETE FROM {self.table_name}"
        return self
    
    def count(self, columns=None): 
        if self.query.startswith("SELECT"):
            self.query = self.query.replace("SELECT", "SELECT COUNT")
            index = self.query.index("COUNT") + 6
            if columns:
                cols = ", ".join(columns) if isinstance(columns, list) else columns
                self.query = self.query[:index] + f'({cols}), ' + self.query[index:]  
            else:
                self.query = self.query[:index] + '(*), ' + self.query[index:]
        return self
    
    def order_by(self, column, order="ASC"):
        self.query += f" ORDER BY {column} {order}"
        return self

    def limit(self, count):
        self.query += f" LIMIT {count}"
        return self
        
    def build(self, include_semicolon=True):
        if include_semicolon:
            if not self.query.endswith(";"):
                self.query += ";"
        else:
            if self.query.endswith(";"):
                self.query = self.query[:-1]
        return self.query

    def reset(self):
        self.query = ""
        return self

    # Add new join methods for more complex queries
    def join(self, table, condition, join_type="INNER"):
        if isinstance(table, QueryGenerator):
            subquery = table.build(include_semicolon=False)
            self.query += f" {join_type} JOIN ({subquery}) ON {condition}"
        else:
            self.query += f" {join_type} JOIN {table} ON {condition}"
        return self
        
    def left_join(self, table, condition):
        return self.join(table, condition, "LEFT")
        
    def right_join(self, table, condition):
        return self.join(table, condition, "RIGHT")
        
    # Add subquery helper
    def subquery(self):
        """Return this query as a subquery (no semicolon)."""
        if not self.query.strip():
            raise ValueError("Cannot create a subquery from an empty query.")
        if not self.query.strip().startswith(("SELECT", "INSERT", "UPDATE", "DELETE")):
            raise ValueError("Subquery must start with a valid SQL command (SELECT, INSERT, UPDATE, DELETE).")
        return f"({self.query})"
    

class Select(QueryGenerator): 
    def __init__(self, table_name):
        super().__init__(table_name)
        self.query = "SELECT "
            
    def distinct(self):
        self.query += "DISTINCT "
        return self

    def top(self, top_n):
        self.query += f"TOP({top_n}) "
        return self
    
    def min(self, column):
        self.query += f"MIN({column}) "
        return self

    def max(self, column):
        self.query += f"MAX({column}) "
        return self
        
    def sum(self, column):
        self.query += f"SUM({column}) "
        return self

    def avg(self, column):
        self.query += f"AVG({column}) "
        return self
    
    def build(self, include_semicolon=True):
        return super().build(include_semicolon=include_semicolon)


class QueryFunctions:
    @staticmethod
    def distinct(query_generator):
        query_generator.query += "DISTINCT "
        return query_generator
        
    @staticmethod
    def top(query_generator, top_n):
        query_generator.query += f"TOP({top_n}) "
        return query_generator

    @staticmethod
    def min(query_generator, column):
        query_generator.query += f"MIN({column}) "
        return query_generator

    @staticmethod
    def max(query_generator, column):
        query_generator.query += f"MAX({column}) "
        return query_generator

    @staticmethod
    def sum(query_generator, column):
        query_generator.query += f"SUM({column}) "
        return query_generator

    @staticmethod
    def avg(query_generator, column):
        query_generator.query += f"AVG({column}) "
        return query_generator


# Map function names to their implementation in the QueryFunctions class
functions = {
    'distinct': QueryFunctions.distinct,
    'top': QueryFunctions.top,
    'min': QueryFunctions.min,
    'max': QueryFunctions.max,
    'sum': QueryFunctions.sum,
    'avg': QueryFunctions.avg
}
