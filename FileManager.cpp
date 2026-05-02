#include "FileManager.h"
#include <fstream>

using namespace std;

void saveData(SystemManager* sys) {
    ofstream file("data.txt");

    auto& users = sys->getUsers();
    auto& comms = sys->getCommunities();

    // ================= USERS =================
    file << users.size() << endl;
    for (auto u : users) {
        file << u->getId() << " "
             << u->getUsername() << " "
             << u->getPassword() << endl;
    }

    // ================= COMMUNITIES =================
    file << comms.size() << endl;

    for (auto c : comms) {
        file << c->getName() << endl;

        auto& posts = c->getPosts();
        file << posts.size() << endl;

        // ================= POSTS =================
        for (auto p : posts) {

            file << p->getId() << endl;
            file << (p->getAuthor() ? p->getAuthor()->getId() : -1) << endl;
            file << p->getVotes() << endl;
            file << p->getText() << endl;

            // ================= COMMENTS =================
            auto& comments = p->getComments();
            file << comments.size() << endl;

            for (auto cmt : comments) {
                file << cmt->getId() << endl;
                file << cmt->getAuthorId() << endl;
                file << cmt->getAuthorName() << endl;
                file << cmt->getText() << endl;
            }

            // ================= VOTES =================
            auto up = p->getUpvotedUsers();
            auto down = p->getDownvotedUsers();

            file << up.size() << endl;
            for (int id : up) file << id << " ";
            file << endl;

            file << down.size() << endl;
            for (int id : down) file << id << " ";
            file << endl;
        }
    }
}

void loadData(SystemManager* sys) {
    ifstream file("data.txt");
    if (!file) return;

    auto& users = sys->getUsers();
    auto& comms = sys->getCommunities();

    // ================= USERS =================
    int userCount;
    file >> userCount;

    for (int i = 0; i < userCount; i++) {
        int id;
        string username, password;

        file >> id >> username >> password;
        users.push_back(new User(username, password, id));
    }

    // ================= COMMUNITIES =================
    int commCount;
    file >> commCount;
    file.ignore();

    for (int i = 0; i < commCount; i++) {

        string name;
        getline(file, name);

        Community* comm = new Community(name);
        comms.push_back(comm);

        int postCount;
        file >> postCount;
        file.ignore();

        // ================= POSTS =================
        for (int j = 0; j < postCount; j++) {

            int postID, authorId, votes;
            string text;

            file >> postID >> authorId >> votes;
            file.ignore();
            getline(file, text);

            // find author
            User* author = nullptr;
            for (auto u : users)
                if (u->getId() == authorId)
                    author = u;

            Post* post = new Post(text, author, postID, votes);

            // ================= COMMENTS =================
            int commentCount;
            file >> commentCount;
            file.ignore();

            for (int k = 0; k < commentCount; k++) {

                int commentID, authorID;
                string authorName, commentText;

                file >> commentID >> authorID;
                file.ignore();

                getline(file, authorName);
                getline(file, commentText);

                post->addComment(
                    new Comment(commentText, authorID, authorName, commentID)
                );
            }

            // ================= UPVOTES =================
            int upCount;
            file >> upCount;

            for (int k = 0; k < upCount; k++) {
                int userID;
                file >> userID;
                post->addUpvotedUser(userID);
            }

            // ================= DOWNVOTES =================
            int downCount;
            file >> downCount;

            for (int k = 0; k < downCount; k++) {
                int userID;
                file >> userID;
                post->addDownvotedUser(userID);
            }

            file.ignore();
            comm->addPost(post);
        }
    }
}