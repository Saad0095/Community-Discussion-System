#include "Comment.h"
#include <iostream>
#include "IDGenerator.h"

using namespace std;

Comment::Comment(string t, int authID, string authName, int id, int v)
    : Content(id == 0 ? IDGenerator<Comment>::next() : id, v) {
    text = t;
    authorId = authID;
    authorName = authName;
}

void Comment::display() {
    cout << "   Comment [" << id << "] by "
         << authorName << ": " << text
         << endl;
}

string Comment::getText() const {
    return text;
}

int Comment::getAuthorId() const {
    return authorId;
}

string Comment::getAuthorName() const {
    return authorName;
}