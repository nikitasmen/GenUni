from . import QueryGenerator
from . import QueryExecutor

class Users: 

    def __init__(self, firstName: str = None, lastName: str = None, countryOrigin: str = None, phone: int = None, birthday: str = None):
        self.user = { 'firstName': firstName, 'lastName': lastName, 'countryOrigin' : countryOrigin, 'phone': phone, 'birthday': birthday}
        self.query_gen = QueryGenerator('User')
        self.query_exec = QueryExecutor()
        # return f"Name: {self.name}"
    
    def addUser(self, user: dict):
        self.user = user
        try: 
            query = self.query_gen.insert(self.user).build()
            return self.query_exec.execute_query(query)
        except Exception as e:
            print(f"Error: {e}")
            
    def getAllUsers(self):
        try: 
            query = self.query_gen.select(['*']).from_table().build()
            return self.query_exec.execute_query(query)
        except Exception as e:
            print(f"Error: {e}")
    
    def getUserById(self, id: int):
        try: 
            query = self.query_gen.select(['*']).from_table().where({'userId': id}).build()
            return self.query_exec.execute_query(query)
        except Exception as e:
            print(f"Error: {e}")
    
    def updateUser(self, id: int, data: dict):
        self.user = data
        try: 
            query = self.query_gen.update(self.user).where({'userId': id}).build()
            return self.query_exec.execute_query(query)
        except Exception as e:
            print(f"Error: {e}")
            
    
    def deleteUser(self, id: int):
        try: 
            deleteComment = QueryGenerator('Comments').delete().where({'userId': id}).build()
            self.query_exec.execute_query(deleteComment)
           
            deletePosts = QueryGenerator('Posts').delete().where({'userId': id}).build()
            self.query_exec.execute_query(deletePosts)
            
            postsUserLikes = QueryGenerator('Likes').select(['postId']).from_table().where({'userId': id}).build()
            postsUserLikes = self.query_exec.execute_query(postsUserLikes)
            
            for post in postsUserLikes:
                postId = post['postId']
                deletePostLike = QueryGenerator('Posts').update({'likes': 'likes - 1'}).where({'id': postId}).build()
                self.query_exec.execute_query(deletePostLike)
            
            deleteLike = QueryGenerator('Likes').delete().where({'userId': id}).build()
            self.query_exec.execute_query(deleteLike)
            
            self.query_exec.execute_query(deleteComment)
            query = self.query_gen.delete().where({'userId': id}).build()
            self.query_exec.execute_query(query)
            return True 
        except Exception as e:
            print(f"Error: {e}")
    
    def get_users_by_tech(self, technology=None):
        try:
            if technology is None:
                query = (
                    "SELECT user.*, Posts.technologies "
                    "FROM user "
                    "JOIN Posts ON User.userId = Posts.userId "
                    "GROUP BY User.userId, Posts.technologies"
                )
                return self.query_exec.execute_query(query)
            else:
                query = (
                    "SELECT User.*, Posts.technologies "
                    "FROM User "
                    "JOIN Posts ON User.userId = Posts.userId "
                    "WHERE Posts.technologies = %s "
                    "GROUP BY User.userId, Posts.technologies"
                )
                return self.query_exec.execute_query(query, (technology,))
        except Exception as e:
            print(f"Error: {e}")
            return None

