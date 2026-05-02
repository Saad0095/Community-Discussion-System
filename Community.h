#ifndef COMMUNITY_H
#define COMMUNITY_H

#include <vector>
#include <string>
#include "Post.h"

class Community {
    string name;
    vector<Post*> posts;

public:
    Community(string n="");

    string getName() const;

    void addPost(Post* p);
    void deletePost(int pid, int userId);

    void displayPosts();
    vector<Post*>& getPosts();

    ~Community();
};

#endif