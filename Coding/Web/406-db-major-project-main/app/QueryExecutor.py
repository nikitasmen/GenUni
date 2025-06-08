from . import Connector
from . import Logger

class QueryExecutor: 
    def __init__(self):
        self.connection = Connector()  # Assuming Connector is a class
        self.logger = Logger()  # Assuming Logger is a class
    
    def execute_query(self, query, params=None):
        """
        Execute SQL query and return appropriate results based on query type
        
        Args:
            query: SQL query string
            params: Optional parameters for parameterized queries
            
        Returns:
            - For SELECT: List of dictionaries with query results
            - For INSERT: Last inserted ID
            - For UPDATE/DELETE: Number of affected rows
            - None if error occurs
        """
        try:
            cursor = self.connection.cursor(dictionary=True)
            
            # Execute the query
            if params:
                cursor.execute(query, params)
            else:
                cursor.execute(query)
            
            # Log the executed query
            self.logger.log(query)
            
            # Handle different query types
            query_type = query.strip().upper().split()[0]
            
            if query_type == "SELECT":
                # For SELECT queries, return fetched data
                result = cursor.fetchall()
                return result
            elif query_type == "INSERT":
                # For INSERT queries, commit and return last inserted ID
                self.connection.commit()
                return cursor.lastrowid()
            else:
                # For UPDATE/DELETE, commit and return affected rows
                self.connection.commit()
                return cursor.rowcount
                
        except Exception as e:
            print(f"Error executing query: {e}")
            return None
        finally:
            if 'cursor' in locals() and cursor:
                cursor.close()