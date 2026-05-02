#include "Content.h"

// Constructor
Content::Content(int i, int v) {
    id = i;
    votes = v;
}

// Destructor
Content::~Content() {}

// Methods
void Content::upvote() {
    votes++;
}

void Content::downvote() {
    votes--;
}

int Content::getId() const {
    return id;
}

int Content::getVotes() const {
    return votes;
}