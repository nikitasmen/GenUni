import mysql.connector

DATABASE_NAME = 'forum'

class Connector:
    def __new__(cls):
        return mysql.connector.connect(
            host="localhost",
            user="root",
            password="",
            database=DATABASE_NAME
        )