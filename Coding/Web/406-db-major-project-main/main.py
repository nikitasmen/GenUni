from app import Connector
from app import Logger
from app import QueryGenerator
from app import ForumMenu
from app import QueryExecutor
from app.QueryGenerator import Select

query = QueryGenerator("users")
logger = Logger()
exec = QueryExecutor()

# exec.execute_query(query.insert({"name": "Nikitas", "lastName": "mekakis", "age": 34}).build())


# logger.log(query.select(["name", "age"]).from_table().where({"name": "John", "age": 30}).build())
# post_id_query = query.select(["id"]).where({"text": "I love programming"})

# comments = QueryGenerator("Comments")
# insert_query = comments.insert({
#     "text": "This is a comment",
#     "best": "0",
#     "postId": post_id_query  # Directly pass the QueryGenerator object
# }).build()

# logger.log(insert_query)
# logger.log(query.select(["name", "age"]).from_table().where({"name": "John", "age": 30}, "OR").count().build())
# logger.log(query.insert({"name": "John", "age": 30}).build())
# logger.log(query.update({"name": "John", "age": 31}).where({"name": "John"}).build())
# logger.log(query.delete().where({"name": "John"}).build())
# logger.log(query.select(["name", "age"], {"top": 5}).from_table().order_by("age").limit(10).build())
# logger.log(query.select(["name", "age"], {"max": 10}).from_table().order_by("age").limit(10).build())
# logger.log(query.select(["name", "age"], {"distinct" : []}).from_table().order_by("age").limit(10).build())

# logger.log(query.reset().select(["name", "age"]).from_table("users").where({"name": "John", "age": 30}).build())
# logger.log(query.select(["country"], options={"distinct": []}).from_table().build())
# logger.log(query.select(["name", "age"], options={"top": [3]}).from_table().build())

# # Use Select for aggregate functions
# logger.log(Select("users").min("reputation").from_table().build())
# logger.log(Select("users").max("reputation").from_table().build())
# logger.log(Select("users").sum("upvotes").from_table().build())
# logger.log(Select("users").avg("score").from_table().build())

# logger.log(query.reset().select(["user_role", "AVG(score)"]).from_table("users").group_by(["user_role"]).build())
# logger.log(query.reset().select(["user_role", "AVG(score)"]).from_table("users").group_by(["user_role"]).having("AVG(score) > 50").build())
ForumMenu = ForumMenu()
ForumMenu.run()