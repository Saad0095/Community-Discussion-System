#ifndef CONTENT_H
#define CONTENT_H

#include <iostream>
using namespace std;

class Content {
protected:
    int id;
    int votes;

public:
    Content(int i=0, int v=0);
    virtual void display() = 0;

    void upvote();
    void downvote();

    int getId() const;
    int getVotes() const;

    virtual ~Content();
};

#endif