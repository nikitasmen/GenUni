from . import QueryGenerator
from . import QueryExecutor
from typing import Dict, List

class Posts:
    def __init__(self, text: str = None, technology_ids: List[int] = None, related_posts: List[int] = None, userId: int = None,  likes: int = None):
        self.post = { 'text': text, 'technologies': technology_ids, 'related_posts': related_posts, 'userId': userId,  'likes': likes}
        self.query_gen = QueryGenerator('Posts')
        self.query_exec = QueryExecutor()
        
    
    def create_post(self, data: Dict[str, str]):
        try:
            self.post = data
            if not(('technologies' in self.post) or ('related_posts' in self.post)):
                print("technologies or related_posts not found in post data")
                return None
            self.post['technologies'] = ','.join(map(str, self.post['technologies']))
            self.post['related_posts'] = ','.join(map(str, self.post['related_posts']))
            self.query_gen.insert(self.post)
            query = self.query_gen.build()
            return self.query_exec.execute_query(query)
        except Exception as e:
            print(f"Error: {e}")
            return None
        
    def getPostById(self, id: int):
        try:
            self.query_gen.select(['*']).from_table().where({'id': id})
            query = self.query_gen.build()
            return self.query_exec.execute_query(query)
        except Exception as e:
            print(f"Error: {e}")
            return None
            
    def get_all_posts(self):
        try:
            self.query_gen.select(['*']).from_table()
            query = self.query_gen.build()
            return self.query_exec.execute_query(query)
        except Exception as e:
            print(f"Error: {e}")
            return None
        
        
    def delete_post(self, id: int):
        try:
            self.query_gen.delete().where({'id': id})
            query = self.query_gen.build()
            return self.query_exec.execute_query(query)
        except Exception as e:
            print(f"Error: {e}")
            return None
        
    def update_post(self, id: int, data: Dict[str, str]):
        try: 
            self.post = data 
            self.query_gen.update(self.post).where({'id': id})
            query = self.query_gen.build()
            return self.query_exec.execute_query(query)            
        except Exception as e:
            print(f"Error: {e}")
            return None
        

    def get_posts_by_tech(self, technology=None):
        try:
            if technology is None:
                query = (
                    "SELECT technologies, COUNT(*) as post_count "
                    "FROM Posts GROUP BY technologies"
                )
                return self.query_exec.execute_query(query)
            else:
                query = (
                    "SELECT * FROM Posts WHERE technologies = %s"
                )
                return self.query_exec.execute_query(query, (technology,))
        except Exception as e:
            print(f"Error: {e}")
            return None
        
    def get_year_of_most_posts_by_tech(self, technology=None):
        try:
            if technology is None:
                query = (
                    "SELECT technologies, COUNT(*) as post_count "
                    "FROM Posts GROUP BY technologies ORDER BY post_count DESC"
                )
                return self.query_exec.execute_query(query)
            else:
                query = (
                    "SELECT technologies, COUNT(*) as post_count "
                    "FROM Posts WHERE technologies = %s GROUP BY technologies ORDER BY post_count DESC"
                )
                return self.query_exec.execute_query(query, (technology,))
        except Exception as e:
            print(f"Error: {e}")
            return None