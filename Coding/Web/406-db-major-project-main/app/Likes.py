from . import QueryExecutor
from . import QueryGenerator

class Likes:
    def __init__(self, userId: int = None, post_id: int = None):
        self.like = {'userId': userId, 'postId': post_id}
        self.query_gen = QueryGenerator('Likes')
        self.query_exec = QueryExecutor()
    
    def add_like(self, data: dict):
        self.like = data
        try:
            query = self.query_gen.insert(self.like).build()
            return self.query_exec.execute_query(query)
        except Exception as e:
            print(f"Error: {e}")
            return None
        return query
    
    def get_all_likesBy_user(self, userId: int):
        try:
            query = self.query_gen.select(['*']).from_table().where({'userId': userId}).build()
            return self.query_exec.execute_query(query)
        except Exception as e:
            print(f"Error: {e}")
            return None
        return query
    
    def get_all_likesBy_post(self, post_id: int):
        try:
            query = self.query_gen.select(['*']).from_table().where({'postId': post_id}).build()
            return self.query_exec.execute_query(query)
        except Exception as e:
            print(f"Error: {e}")
            return None
        return query
    
    def delete_like(self, userId: int, post_id: int):
        try:
            query = self.query_gen.delete().where({'userId': userId, 'postId': post_id}).build()
            return self.query_exec.execute_query(query)
        except Exception as e:
            print(f"Error: {e}")
            return None
        return query   
    
    