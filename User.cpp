#include "User.h"
#include "Post.h"
#include <stdexcept>

User::User(string u, string p, int id) {
    this->id = (id==0?IDGenerator<User>::next():id);
    username = u;
    password = p;
}

string User::getUsername() const { return username; }
string User::getPassword() const { return password; }
int User::getId() const { return id; }

bool User::login(string u, string p) {
    return (username==u && password==p);
}

Post* User::createPost(string text) {
    if (text.empty()) throw runtime_error("Post cannot be empty!");
    return new Post(text, this);
}