#include "Community.h"
#include "User.h"
#include <iostream>
using namespace std;

Community::Community(string n) : name(n) {}

string Community::getName() const { return name; }

void Community::addPost(Post* p) {
    if (!p) throw runtime_error("Invalid post!");
    posts.push_back(p);
}

void Community::deletePost(int postID, int userID) {
    for (auto it = posts.begin(); it != posts.end(); ++it) {
        if ((*it)->getId() == postID) {

            if ((*it)->getAuthor() == nullptr ||
                (*it)->getAuthor()->getId() != userID) {
                throw runtime_error("You can only delete your own post!");
            }

            delete *it;
            posts.erase(it);
            return;
        }
    }
    throw runtime_error("Post not found!");
}

void Community::displayPosts() {
    cout << "--- " << name << " ---\n";
        if (posts.empty())
    {
        cout << "No posts available.\n";
        return;
    }
    for (auto p : posts) {
        p->display();
        cout << "----------------\n";
    }
}

vector<Post*>& Community::getPosts() { return posts; }

Community::~Community() {
    for (auto p : posts) delete p;
}