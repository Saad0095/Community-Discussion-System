#ifndef USER_H
#define USER_H

#include <string>
#include "IDGenerator.h"
using namespace std;

class Post;

class User {
    int id;
    string username;
    string password;

public:
    User(string u="", string p="", int id=0);

    string getUsername() const;
    string getPassword() const;
    int getId() const;

    bool login(string u, string p);
    Post* createPost(string text);
};

#endif