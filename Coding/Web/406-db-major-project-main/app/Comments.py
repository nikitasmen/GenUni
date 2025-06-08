from . import QueryExecutor
from . import QueryGenerator

class Comments:
    def __init__(self, text: str = None, post_id: int = None, userId: int = None):
        self.comment = {'text': text, 'post_id': post_id, 'userId': userId}
        self.query_gen = QueryGenerator('Comments')
        self.query_exec = QueryExecutor()
        
    def create_comment(self, data: dict):
        try:
            self.comment = data
            self.query_gen.insert(self.comment)
            query = self.query_gen.build()
            return self.query_exec.execute(query)
        except Exception as e:
            print(f"Error: {e}")
            return None
        
    def getCommentsByPostId(self, post_id: int):
        try:
            self.query_gen.select(['*']).from_table().where({'post_id': post_id})
            query = self.query_gen.build()
            return self.query_exec.execute(query)
        except Exception as e:
            print(f"Error: {e}")
            return None
       
    def getCommentsByUserId(self, userId: int):
        try:
            self.query_gen.select(['*']).from_table().where({'userId': userId})
            query = self.query_gen.build()
            return self.query_exec.execute(query)
        except Exception as e:
            print(f"Error: {e}")
            return None 
 
        
    def delete_comment(self, id: int):
        try:
            self.query_gen.delete().where({'id': id})
            query = self.query_gen.build()
            return self.query_exec.execute(query)
        except Exception as e:
            print(f"Error: {e}")
            return None