#ifndef POST_H
#define POST_H

#include "Content.h"
#include "Comment.h"
#include <vector>
#include <set>

class User;

class Post : public Content {
    string text;
    User* author;
    vector<Comment*> comments;
    set<int> upvotedUsers;
    set<int> downvotedUsers;

public:
    Post(string t="", User* u=nullptr, int id=0, int v=0);

    void addComment(Comment* c);
    void deleteComment(int commentID, int userID);

    void display() override;

    string getText() const;
    vector<Comment*>& getComments();
    User* getAuthor() const;

    void upvote(User* user);
    void downvote(User* user);

    const set<int>& getUpvotedUsers() const { return upvotedUsers; }
    const set<int>& getDownvotedUsers() const { return downvotedUsers; }

    void addUpvotedUser(int id) { upvotedUsers.insert(id); }
    void addDownvotedUser(int id) { downvotedUsers.insert(id); }
    
    ~Post();
};

#endif