#include "Post.h"
#include "User.h"
#include <iostream>
using namespace std;

Post::Post(string t, User* u, int id, int v)
    : Content(id==0?IDGenerator<Post>::next():id, v), text(t), author(u) {}

void Post::addComment(Comment* c) {
    if (!c) throw runtime_error("Invalid comment!");
    comments.push_back(c);
}

void Post::deleteComment(int cid, int userId) {
    for (auto it = comments.begin(); it != comments.end(); ++it) {
        if ((*it)->getId() == cid) {

            if ((*it)->getAuthorId() != userId) {
                throw runtime_error("You can only delete your own comment!");
            }

            delete *it;
            comments.erase(it);
            return;
        }
    }
    throw runtime_error("Comment not found!");
}

void Post::display() {
    cout << "Post [" << id << "] by "
         << (author ? author->getUsername() : "Unknown") << "\n";
    cout << "  " << text << " (Votes: " << votes << ")\n";
    for (auto c : comments) c->display();
}

string Post::getText() const { return text; }
vector<Comment*>& Post::getComments() { return comments; }
User* Post::getAuthor() const { return author; }

Post::~Post() {
    for (auto c : comments) delete c;
}

void Post::upvote(User* user) {
    int uid = user->getId();

    if (upvotedUsers.count(uid)) {
        throw runtime_error("You already upvoted this post!");
    }

    if (downvotedUsers.count(uid)) {
        downvotedUsers.erase(uid);
        votes++; // cancel previous downvote
    }

    upvotedUsers.insert(uid);
    votes++;
}

void Post::downvote(User* user) {
    int uid = user->getId();

    if (downvotedUsers.count(uid)) {
        throw runtime_error("You already downvoted this post!");
    }

    if (upvotedUsers.count(uid)) {
        upvotedUsers.erase(uid);
        votes--; // cancel previous upvote
    }

    downvotedUsers.insert(uid);
    votes--;
}