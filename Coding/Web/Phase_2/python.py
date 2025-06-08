import mysql.connector
from mysql.connector import Error


# Όνομα βάσης που θα χρησιμοποιήσουμε
DATABASE_NAME = 'forum'


# Σύνδεση στη βάση
def connect_to_db():
    try:
        connection = mysql.connector.connect(
            host='localhost',
            user='root',
            database=DATABASE_NAME
        )
        return connection
    except Error as e:
        print(f"Σφάλμα σύνδεσης: {e}")
        return None		#similar to null



# User input
def insert_user(conn):
    id = input("Id: ")
    dob = input("Date of Birth: ")
    age = input("Age: ")
    ethnicity = input("Ethnicity: ")
    first = input("First: ")
    last = input("Last: ")
    try:
        cursor = conn.cursor()
        cursor.execute("INSERT INTO user (id, dob, age, ethnicity, first, last) VALUES (%s, %s, %s, %s, %s, %s)", (id, dob, age, ethnicity, first, last))
        conn.commit()
        print("User added")
    except Error as e:
        print(f"Input error: {e}")

# Upload post
def upload_post(conn):
    id = input("Post Id: ")
    post_id = id
    user_id = input("User id: ") 
    date_time = input("Date and time: ")
    content = input("Post text: ")
    text = content
    tech_id = input("Technology ID: ")
    technology_name = input("Technology name: ")
    num_comment = input("Number of comments this technology has: ")
    num_like = input("Number of likes this technology has: ")
    try:
        cursor = conn.cursor()
        cursor.execute("INSERT INTO post (id, text, user_id, tech_id) VALUES (%s, %s, %s, %s)", (id, text, user_id, tech_id))
        cursor.execute("INSERT INTO technologies (id, num_like, num_comment, post_id, technology_name) VALUES (%s, %s, %s, %s, %s)", (tech_id, num_like, num_comment, post_id,technology_name))
        cursor.execute("INSERT INTO user_upload_post (id, user_id, date_time, post_id, content, tech_id) VALUES (%s, %s, %s, %s, %s, %s)", (id, user_id, date_time, post_id, content,tech_id))
        conn.commit()
        print("Post uploaded")
    except Error as e:
        print(f"Upload error: {e}")



# Delete user
def delete_user(conn):
    user_id = input("ID of the user you want to delete: ")
    try:
        cursor = conn.cursor()
        cursor.execute("DELETE FROM admin WHERE user_id = %s", (user_id,))
        cursor.execute("DELETE FROM expert WHERE user_id = %s", (user_id,))
        cursor.execute("DELETE FROM phones WHERE user_id = %s", (user_id,))
        cursor.execute("DELETE FROM technologies WHERE user_id = %s", (user_id,))
        cursor.execute("DELETE FROM user WHERE id = %s", (user_id,))  
        cursor.execute("DELETE FROM user_comment_post WHERE user_id = %s", (user_id,))
        cursor.execute("DELETE FROM user_is_admin WHERE user_id = %s", (user_id,))
        cursor.execute("DELETE FROM user_like_post WHERE user_id = %s", (user_id,))
        cursor.execute("DELETE FROM user_upload_post WHERE user_id = %s", (user_id,))
        cursor.execute("DELETE FROM post WHERE user_id = %s", (user_id,))  
        conn.commit()
        if cursor.rowcount == 0:
            print("No user with that ID.")
        else: 
            print("User deleted.")
    except Error as e:
        print(f"Delete error: {e}")




def tech_statistics(conn): 
    try:
        cursor = conn.cursor()
        query = """
        WITH posts_per_year AS (
            SELECT 
                t.id AS tech_id,
                t.technology_name,
                YEAR(u.date_time) AS year,
                COUNT(*) AS posts_in_year
            FROM technologies t
            LEFT JOIN post p ON t.id = p.tech_id
            LEFT JOIN user_upload_post u ON u.post_id = p.id
            GROUP BY t.id, year
        ),
        ranked_years AS (
            SELECT *,
                   RANK() OVER (PARTITION BY tech_id ORDER BY posts_in_year DESC) AS rnk
            FROM posts_per_year
        )
        SELECT 
            t.technology_name,
            COUNT(p.tech_id) AS post_count,
            COUNT(DISTINCT p.user_id) AS user_count,
            ry.year AS top_year
        FROM technologies t
        LEFT JOIN post p ON t.id = p.tech_id
        LEFT JOIN ranked_years ry ON t.id = ry.tech_id AND ry.rnk = 1
        GROUP BY t.id
        ORDER BY post_count DESC;
        """
        cursor.execute(query)
        results = cursor.fetchall()
        for tech_name, post_count, user_count, top_year in results:
            print(f"Technology: {tech_name} - Posts related: {post_count} - Users related: {user_count} - Top Year: {top_year}")
    except Error as e:
        print(f"Σφάλμα στα στατιστικά: {e}")






# Μενού εφαρμογής
def menu():
    conn = connect_to_db()
	
    if conn is None:
        return

    while True:
        print("\n Choices:")
        print("1. Insert user")
        print("2. Upload post")
        print("3. Delete user")
        print("4. Calculate statistics for Technologies")
        print("5. Quit")

        choice = input("Choice: ")

        if choice == '1':
            insert_user(conn)
        elif choice == '2':
            upload_post(conn)
        elif choice == '3':
            delete_user(conn)
        elif choice == '4':
            tech_statistics(conn)
        elif choice == '5':
            print("Goodbye.")
            break
        else:
            print("Not valid choise. Choose from 1 to 5.")
    conn.close()


# Εκτέλεση εφαρμογής
if __name__ == "__main__":
    menu()



