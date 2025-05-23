#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Users {
private:
    int id;
    char name;
    int age;
    string friend_id;

public:
    Users(string data) {
        vector<string> lines;
        stringstream ss(data);
        string line;
        while (getline(ss, line, ',')) {
            lines.push_back(line);
        }
        this->id = stoi(lines[0]);
        this->name = lines[1][0];
        this->age = stoi(lines[2]);
        this->friend_id = lines[3];
    }

    int get_id() { return this->id; }
    string get_friends() { return this->friend_id; }

    int number_of_friends() {
        int count = 0;
        for (int i = 0; i < friend_id.length(); i++) {
            if (friend_id[i] == ' ') {
                count++;
            }
        }
        return count + 1;
    }

    int get_age() { return this->age; }

    //Daskalos eimai vlaka den kserei svisei ola. 
    //Id -1 means that the user is deleted  
    void erase() {
        this->id = -1;
        this->name = ' ';
        this->age = -1;
        this->friend_id = ' ';
    }

    void set_friend_id(string new_friend_id) {
        //update friend id by adding the new friend id to the existing list
        //append the friendId string 
        this->friend_id += new_friend_id + " ";
    }
};

vector<Users> initialization(string filename) {
    vector<Users> alldata;
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cout << "error can not read";
        exit(1);
    }
    string data;
    while (getline(fin, data)) {
        alldata.push_back(Users(data));
    }
    return alldata;
}

void add_friend(vector<Users>& users, int user1_id, int user2_id) {
    for (int i = 0; i < users.size(); i++) {
        Users& user = users[i];
        if (user.get_id() == user1_id || user.get_id() == user2_id) {
            string new_friend_id;
            if (user.get_friends().find(to_string(user2_id) + " ") == string::npos) {
                new_friend_id = user.get_friends();
            } else {
                new_friend_id = user.get_friends().substr(0, user.get_friends().find(to_string(user2_id) + " ")) +
                                 to_string(user1_id) + " " +
                                 user.get_friends().substr(user.get_friends().find(to_string(user2_id) + " ") + 3);
            }
            if (user.get_id() == user1_id) {
                user.set_friend_id(new_friend_id);
            } else if (user.get_id() == user2_id) {
                for (int j = i; j < users.size(); j++) {
                    Users& other_user = users[j];
                    if (other_user.get_id() == user1_id) {
                        other_user.set_friend_id(new_friend_id);
                        break;
                    }
                }
            }
        }
    }
}

void remove_user(vector<Users>& users, int user_id) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].get_id() == user_id) {
            users.erase(users.begin() + i);
            break;
        }
    }
}

double compute_avg_num_of_friends(vector<Users>& users, int age) {
    double total_friend_count = 0.0;
    int user_count = 0;
    for (int i = 0; i < users.size(); i++) {
        Users& user = users[i];
        if (user.get_age() == age) {
            total_friend_count += user.number_of_friends();
            user_count++;
        }
    }
    return total_friend_count / user_count;
}

void find_most_popular_user(vector<Users>& users) {
    int max_friend_count = 0;
    int most_popular_user_id = -1;
    for (int i = 0; i < users.size(); i++) {
        Users& user = users[i];
        if (user.number_of_friends() > max_friend_count) {
            max_friend_count = user.number_of_friends();
            most_popular_user_id = user.get_id();
        }
    }
    cout << "Most popular user: " << most_popular_user_id << endl;
}

int main() {
  
    vector<Users> users = initialization("input_assignment_1.1_25.txt");
    add_friend(users, 1001, 1010);
    remove_user(users, 1010);
    double avg_friends_at_age30 = compute_avg_num_of_friends(users, 30);
    find_most_popular_user(users);
    return 0;
}
