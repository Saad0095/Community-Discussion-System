#include "FileManager.h"
#include <fstream>
#include <limits>

using namespace std;

void saveData(SystemManager* sys) {
    ofstream file("data.txt");

    auto& users = sys->getUsers();
    auto& comms = sys->getCommunities();

    file << "USERS " << users.size() << endl;
    for (auto u : users) {
        file << u->getId() << " "
             << u->getUsername() << " "
             << u->getPassword() << endl;
    }

    file << "COMMUNITIES " << comms.size() << endl;

    for (auto c : comms) {
        file << "COMMUNITY " << c->getName() << endl;

        auto& posts = c->getPosts();
        file << "POSTS " << posts.size() << endl;

        for (auto p : posts) {

            file << "POST " << p->getId() << endl;
            file << "AUTHOR " << (p->getAuthor() ? p->getAuthor()->getId() : -1) << endl;
            file << "VOTES " << p->getVotes() << endl;
            file << "TEXT " << p->getText() << endl;

            auto& comments = p->getComments();
            file << "COMMENTS " << comments.size() << endl;

            for (auto cmt : comments) {
                file << "COMMENT " << cmt->getId() << endl;
                file << "C_AUTHOR_ID " << cmt->getAuthorId() << endl;
                file << "C_AUTHOR_NAME " << cmt->getAuthorName() << endl;
                file << "C_TEXT " << cmt->getText() << endl;
            }

            auto up = p->getUpvotedUsers();
            auto down = p->getDownvotedUsers();

            file << "UPVOTES " << up.size() << endl;
            for (int id : up) file << id << " ";
            file << endl;

            file << "DOWNVOTES " << down.size() << endl;
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

    users.clear();
    comms.clear();

    string label;

    int userCount;
    file >> label >> userCount;
    file.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < userCount; i++) {
        int id;
        string username, password;

        file >> id >> username >> password;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        users.push_back(new User(username, password, id));
    }

    int commCount;
    file >> label >> commCount;
    file.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < commCount; i++) {
        string name;
        file >> label; 
        file.ignore(); 
        getline(file, name);

        Community* comm = new Community(name);
        comms.push_back(comm);

        // POSTS
        int postCount;
        file >> label >> postCount;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int j = 0; j < postCount; j++) {

            int postID, authorId, votes;
            string text;

            file >> label >> postID;
            file.ignore(numeric_limits<streamsize>::max(), '\n');

            file >> label >> authorId;
            file.ignore(numeric_limits<streamsize>::max(), '\n');

            file >> label >> votes;
            file.ignore(numeric_limits<streamsize>::max(), '\n');

            file >> label;
            file.ignore();
            getline(file, text);

            User* author = nullptr;
            for (auto u : users)
                if (u->getId() == authorId)
                    author = u;

            Post* post = new Post(text, author, postID, votes);

            int commentCount;
            file >> label >> commentCount;
            file.ignore(numeric_limits<streamsize>::max(), '\n');

            for (int k = 0; k < commentCount; k++) {

                int commentID, authorID;
                string authorName, commentText;

                file >> label >> commentID;
                file.ignore(numeric_limits<streamsize>::max(), '\n');

                file >> label >> authorID;
                file.ignore(numeric_limits<streamsize>::max(), '\n');

                file >> label;
                file.ignore();
                getline(file, authorName);

                file >> label;
                file.ignore();
                getline(file, commentText);

                post->addComment(
                    new Comment(commentText, authorID, authorName, commentID)
                );
            }

            int upCount;
            file >> label >> upCount;

            for (int k = 0; k < upCount; k++) {
                int id;
                file >> id;
                post->addUpvotedUser(id);
            }
            file.ignore(numeric_limits<streamsize>::max(), '\n');

            int downCount;
            file >> label >> downCount;

            for (int k = 0; k < downCount; k++) {
                int id;
                file >> id;
                post->addDownvotedUser(id);
            }
            file.ignore(numeric_limits<streamsize>::max(), '\n');

            comm->addPost(post);
        }
    }
}