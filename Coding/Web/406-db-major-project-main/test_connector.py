'''
from app import Connector
print("Trying to connect...")
db = Connector(host='localhost', user='root', password='') # Adjust host/user/password if needed
print("Database connection established successfully.")
'''

import mysql.connector

connection = mysql.connector.connect(host="localhost", user="root", password="", database="forum")

if connection.is_connected():
    print("Connected Successfully")
else:
    print("Failed to connect")

connection.close()
