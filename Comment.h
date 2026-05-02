#ifndef COMMENT_H
#define COMMENT_H

#include "Content.h"
#include <string>

using namespace std;

class Comment : public Content {
    string text;
    int authorId;
    string authorName;

public:
    Comment(string t = "", int aid = 0, string aname = "", int id = 0, int v = 0);

    void display() override;

    string getText() const;
    int getAuthorId() const;
    string getAuthorName() const;
};

#endif