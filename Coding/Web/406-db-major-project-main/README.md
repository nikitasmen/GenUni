# 406-db-major-project

This project involves designing and implementing a relational database for an online developer forum, similar to Stack Overflow.

## Project Structure

- **Sql/**: Contains SQL schema and queries
  - `Db.sql`: Database schema definition for the Forum database
  - `queries.phase01.sql`: Example queries for user and content management

- **app/**: Python application modules
  - `Connector.py`: Database connection handling
  - `Logger.py`: Logging functionality for SQL operations
  - `QueryGenerator.py`: SQL query builder with fluent interface

- **data/**: Contains logs and data files
  - `log.txt`: SQL operation logs

## Features

- Database schema for users, experts, posts, comments, and technologies
- Query generation with a fluent interface
- Logging system for SQL operations
- User management (create, update, delete)
- Content management (posts, comments)
- Technology tagging system

## Setup

1. Ensure MySQL is installed and running
2. Install dependencies: `pip install -r requirements.txt`
3. Run the main script: `python main.py`

## Database Structure

The database includes tables for:
- User management (User, UserExpert, UserAdmin)
- Content (Posts, Comments)
- Technology tags (Tech, TechPost, UserTech)
- User relationships (UserFriends)
- Activity tracking (UserAction)
