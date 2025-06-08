import os
from . import Users, Posts, Comments, Likes

class ForumMenu:
    def __init__(self):
        self.users = Users()
        self.posts = Posts()
        self.comments = Comments()
        self.likes = Likes()
        # Create a default guest user
        self.current_user = {'id': 1, 'firstName': 'Guest', 'lastName': 'User'}
    
    def clear_console(self):
        """Clear the console screen"""
        os.system('cls' if os.name == 'nt' else 'clear')
        # Use 'cls' for Windows: os.system('cls')
    
    def display_main_menu(self):
        self.clear_console()
        print("\n===== Developer Forum =====")
        print("1. Register New User")
        print("2. View Profile")
        print("3. Delete User")
        print("4. View Posts")
        print("5. Create Post")
        print("6. View Stats")
        print("7. Exit")
        return self.get_user_choice(1, 7)
    
    def get_user_choice(self, min_value, max_value):
        while True:
            try:
                choice = int(input("\nPlease enter your choice: "))
                if min_value <= choice <= max_value:
                    return choice
                print(f"Please enter a number between {min_value} and {max_value}")
            except ValueError:
                print("Please enter a valid number")
    
    def get_user_input(self, prompt):
        return input(f"{prompt}: ")
    
    def register_user(self):
        self.clear_console()
        print("\n===== User Registration =====")
        user_data = {
            'firstName': self.get_user_input("First Name"),
            'lastName': self.get_user_input("Last Name"),
            'countryOrigin': self.get_user_input("Country"),
            'phone': self.get_user_input("Phone Number"),
            'birthday': self.get_user_input("Birthday (YYYY-MM-DD)"),
        }
        self.users.addUser(user_data)
        print("User registered successfully!")
        self.current_user = user_data        
        input("\nPress Enter to continue...")
        
    def delete_user(self): 
        self.clear_console()
        print("\n===== Delete User =====")
        userId = self.get_user_input("Enter User ID to delete")
        if self.users.deleteUser(userId):
            print("User deleted successfully!")
            self.current_user = {'id': 1, 'firstName': 'Guest', 'lastName': 'User'}
        else:
            print("User not found or could not be deleted!")
        input("\nPress Enter to continue...")

    def display_profile(self):
        self.clear_console()
        print("\n===== Current User Profile =====")
        print(f"Name: {self.current_user['firstName']} {self.current_user['lastName']}")
        # Display other user information as needed
        
        # Option to switch to another user
        print("\n1. Edit Profile")
        print("2. Switch User")
        print("3. Return to Main Menu")
        
        choice = self.get_user_choice(1, 3)
        if choice == 1:
            self.edit_profile()
        elif choice == 2:
            self.switch_user()
    
    def switch_user(self):
        self.clear_console()
        print("\n===== Switch User =====")
        userId = self.get_user_input("Enter User ID")
        user = self.fetch_user_by_id(userId)
        if user:
            self.current_user = user
            print(f"Now acting as: {self.current_user['firstName']} {self.current_user['lastName']}")
        else:
            print("User not found!")
        input("\nPress Enter to continue...")
    
    def fetch_user_by_id(self, userId):
        return self.users.getUserById(userId)
    
    def edit_profile(self):
        self.clear_console()
        print("\n===== Edit Profile =====")
        print("1. Edit Name")
        print("2. Edit Country")
        print("3. Edit Phone")
        print("4. Return")
        choice = self.get_user_choice(1, 4)
        
        if choice == 1:
            firstName = self.get_user_input("New First Name")
            lastName = self.get_user_input("New Last Name")
            # Update user data
            data = {'firstName': firstName, 'lastName': lastName}
            self.users.updateUser(self.current_user['id'], data)
            self.current_user['firstName'] = firstName
            self.current_user['lastName'] = lastName
            print("Name updated successfully!")
        elif choice == 2:
            country = self.get_user_input("New Country")
            self.users.updateUser(self.current_user['id'], {'countryOrigin': country})
            print("Country updated successfully!")
        elif choice == 3:
            phone = self.get_user_input("New Phone")
            self.users.updateUser(self.current_user['id'], {'phone': phone})
            print("Phone updated successfully!")
        input("\nPress Enter to continue...")
    
    def create_post(self):
        self.clear_console()
        print("\n===== Create Post =====")
        text = self.get_user_input("Post content")
        technologies = input("Technologies (comma-separated IDs): ").split(',')
        related_posts = input("Related Posts (comma-separated IDs, leave empty if none): ")
        related_posts = related_posts.split(',') if related_posts else []
        
        post_data = {
            'text': text,
            'technologies': technologies,
            'related_posts': related_posts,
            'userId': self.current_user['id'],
            'likes': 0
        }
        
        self.posts.create_post(post_data)
        print("Post created successfully!")
        input("\nPress Enter to continue...")
    
    def view_stats(self):
        self.clear_console()
        print("\n===== Forum Statistics =====")
        posts_by_tech = self.posts.get_posts_by_tech()
        users_by_tech = self.users.get_users_by_tech()
        year_of_most_posts_by_tech = self.posts.get_year_of_most_posts_by_tech()
        
        ##Probably is a table. Should be displayed in a better way 
        print("Posts by Technology:", posts_by_tech)
        print("Users by Technology:", users_by_tech)
        print("Year of Most Posts by Technology:", year_of_most_posts_by_tech)   
        
        input("\nPress Enter to continue...")
    
    def view_posts(self):
        self.clear_console()
        print("\n===== Posts =====")
        posts = self.posts.get_all_posts()
        if not posts:
            print("No posts available.")
        else: 
            for post in posts:
                print(f"Post ID: {post['id']}, Content: {post['text']}, Likes: {post['likes']}")
        print("\nSelect a post to view details:")       
        print("3. Return")
        
        choice = self.get_user_choice(1, len(posts)+1)
        self.display_post_details(choice)
        post_action = self.display_post_menu(choice)
        self.handle_post_action(choice, post_action)

    def display_post_menu(self):
        self.clear_console()
        print("\n===== Post Actions =====")
        print("1. View Comments")
        print("2. Add Comment")
        print("3. Like Post")
        print("4. Return to Posts")
        return self.get_user_choice(1, 4)
    
    def display_post_details(self, post_id):
        self.clear_console()
        print(f"\n===== Post {post_id} Details =====")
        posts = self.posts.getPostById(post_id)
        if posts:
            print(f"Post ID: {post_id}")
            print(f"Content: {posts['text']}")
            print(f"Technologies: {posts['technologies']}")
            print(f"Related Posts: {posts['related_posts']}")
            print(f"Likes: {posts['likes']}")
        else:
            print("Post not found!")
        input("\nPress Enter to continue...")
    
    def handle_post_action(self, post_id, action):
        if action == 1:  # View comments
            self.view_comments(post_id)
        elif action == 2:  # Add comment
            self.add_comment(post_id)
        elif action == 3:  # Like post
            self.like_post(post_id)
    
    def view_comments(self, post_id):
        self.clear_console()
        print(f"\n===== Comments for Post {post_id} =====")
        comments = self.comments.getCommentsByPostId(post_id)
        for comment in comments:
            print(f"Comment ID: {comment['id']}, User ID: {comment['userId']}, Text: {comment['text']}")
        if not comments:
            print("No comments available for this post.")
        input("\nPress Enter to continue...")
    
    def add_comment(self, post_id):
        self.clear_console()
        text = self.get_user_input("\nEnter your comment")
        comment_data = {
            'text': text,
            'post_id': post_id,
            'userId': self.current_user['id']
        }
        self.comments.create_comment(comment_data)
        print("Comment added successfully!")
        input("\nPress Enter to continue...")
    
    def like_post(self, post_id):
        self.clear_console()
        like_data = {
            'userId': self.current_user['id'],
            'postId': post_id
        }
        self.likes.add_like(like_data)
        print("Post liked!")
        input("\nPress Enter to continue...")
    
    def run(self):
        while True:
            choice = self.display_main_menu()
            if choice == 1:
                self.register_user()
            elif choice == 2:
                self.display_profile()
            elif choice == 3:
                self.delete_user() 
            elif choice == 4:
                self.view_posts()
            elif choice == 5:
                self.create_post()
            elif choice == 6:
                self.view_stats()
            elif choice == 7:
                self.clear_console()
                print("Goodbye!")
                break
