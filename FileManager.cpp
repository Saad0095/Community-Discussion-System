// // #include "FileManager.h"
// // #include <fstream>

// // using namespace std;

// // void saveData(SystemManager* sys) {
// //     ofstream file("data.txt");

// //     auto& users = sys->getUsers();
// //     auto& comms = sys->getCommunities();

// //     // ================= USERS =================
// //     file << users.size() << endl;
// //     for (auto u : users) {
// //         file << u->getId() << " "
// //              << u->getUsername() << " "
// //              << u->getPassword() << endl;
// //     }

// //     // ================= COMMUNITIES =================
// //     file << comms.size() << endl;

// //     for (auto c : comms) {
// //         file << c->getName() << endl;

// //         auto& posts = c->getPosts();
// //         file << posts.size() << endl;

// //         // ================= POSTS =================
// //         for (auto p : posts) {

// //             file << p->getId() << endl;
// //             file << (p->getAuthor() ? p->getAuthor()->getId() : -1) << endl;
// //             file << p->getVotes() << endl;
// //             file << p->getText() << endl;

// //             // ================= COMMENTS =================
// //             auto& comments = p->getComments();
// //             file << comments.size() << endl;

// //             for (auto cmt : comments) {
// //                 file << cmt->getId() << endl;
// //                 file << cmt->getAuthorId() << endl;
// //                 file << cmt->getAuthorName() << endl;
// //                 file << cmt->getText() << endl;
// //             }

// //             // ================= VOTES =================
// //             auto up = p->getUpvotedUsers();
// //             auto down = p->getDownvotedUsers();

// //             file << up.size() << endl;
// //             for (int id : up) file << id << " ";
// //             file << endl;

// //             file << down.size() << endl;
// //             for (int id : down) file << id << " ";
// //             file << endl;
// //         }
// //     }
// // }

// // void loadData(SystemManager* sys) {
// //     ifstream file("data.txt");
// //     if (!file) return;

// //     auto& users = sys->getUsers();
// //     auto& comms = sys->getCommunities();

// //     // ================= USERS =================
// //     int userCount;
// //     file >> userCount;

// //     for (int i = 0; i < userCount; i++) {
// //         int id;
// //         string username, password;

// //         file >> id >> username >> password;
// //         users.push_back(new User(username, password, id));
// //     }

// //     // ================= COMMUNITIES =================
// //     int commCount;
// //     file >> commCount;
// //     file.ignore();

// //     for (int i = 0; i < commCount; i++) {

// //         string name;
// //         getline(file, name);

// //         Community* comm = new Community(name);
// //         comms.push_back(comm);

// //         int postCount;
// //         file >> postCount;
// //         file.ignore();

// //         // ================= POSTS =================
// //         for (int j = 0; j < postCount; j++) {

// //             int postID, authorId, votes;
// //             string text;

// //             file >> postID >> authorId >> votes;
// //             file.ignore();
// //             getline(file, text);

// //             // find author
// //             User* author = nullptr;
// //             for (auto u : users)
// //                 if (u->getId() == authorId)
// //                     author = u;

// //             Post* post = new Post(text, author, postID, votes);

// //             // ================= COMMENTS =================
// //             int commentCount;
// //             file >> commentCount;
// //             file.ignore();

// //             for (int k = 0; k < commentCount; k++) {

// //                 int commentID, authorID;
// //                 string authorName, commentText;

// //                 file >> commentID >> authorID;
// //                 file.ignore();

// //                 getline(file, authorName);
// //                 getline(file, commentText);

// //                 post->addComment(
// //                     new Comment(commentText, authorID, authorName, commentID)
// //                 );
// //             }

// //             // ================= UPVOTES =================
// //             int upCount;
// //             file >> upCount;

// //             for (int k = 0; k < upCount; k++) {
// //                 int userID;
// //                 file >> userID;
// //                 post->addUpvotedUser(userID);
// //             }

// //             // ================= DOWNVOTES =================
// //             int downCount;
// //             file >> downCount;

// //             for (int k = 0; k < downCount; k++) {
// //                 int userID;
// //                 file >> userID;
// //                 post->addDownvotedUser(userID);
// //             }

// //             file.ignore();
// //             comm->addPost(post);
// //         }
// //     }
// // }











// #include "FileManager.h"
// #include <fstream>
// #include <limits>   // IMPORTANT

// using namespace std;

// // ================= SAVE =================
// void saveData(SystemManager* sys) {
//     ofstream file("data.txt");

//     auto& users = sys->getUsers();
//     auto& comms = sys->getCommunities();

//     // ================= USERS =================
//     file << users.size() << endl;
//     for (auto u : users) {
//         file << u->getId() << " "
//              << u->getUsername() << " "
//              << u->getPassword() << endl;
//     }

//     // ================= COMMUNITIES =================
//     file << comms.size() << endl;

//     for (auto c : comms) {
//         file << c->getName() << endl;

//         auto& posts = c->getPosts();
//         file << posts.size() << endl;

//         // ================= POSTS =================
//         for (auto p : posts) {

//             file << p->getId() << endl;
//             file << (p->getAuthor() ? p->getAuthor()->getId() : -1) << endl;
//             file << p->getVotes() << endl;
//             file << p->getText() << endl;

//             // ================= COMMENTS =================
//             auto& comments = p->getComments();
//             file << comments.size() << endl;

//             for (auto cmt : comments) {
//                 file << cmt->getId() << endl;
//                 file << cmt->getAuthorId() << endl;
//                 file << cmt->getAuthorName() << endl;
//                 file << cmt->getText() << endl;
//             }

//             // ================= VOTES =================
//             auto up = p->getUpvotedUsers();
//             auto down = p->getDownvotedUsers();

//             file << up.size() << endl;
//             for (int id : up) file << id << " ";
//             file << endl;

//             file << down.size() << endl;
//             for (int id : down) file << id << " ";
//             file << endl;
//         }
//     }
// }

// // ================= LOAD =================
// void loadData(SystemManager* sys) {
//     ifstream file("data.txt");
//     if (!file) return;

//     auto& users = sys->getUsers();
//     auto& comms = sys->getCommunities();

//     // ================= USERS =================
//     int userCount;
//     file >> userCount;
//     file.ignore(numeric_limits<streamsize>::max(), '\n');  // FIX

//     for (int i = 0; i < userCount; i++) {
//         int id;
//         string username, password;

//         file >> id >> username >> password;
//         file.ignore(numeric_limits<streamsize>::max(), '\n');  // FIX

//         users.push_back(new User(username, password, id));
//     }

//     // ================= COMMUNITIES =================
//     int commCount;
//     file >> commCount;
//     file.ignore(numeric_limits<streamsize>::max(), '\n');  // FIX

//     for (int i = 0; i < commCount; i++) {

//         string name;
//         getline(file, name);   // now safe

//         Community* comm = new Community(name);
//         comms.push_back(comm);

//         int postCount;
//         file >> postCount;
//         file.ignore(numeric_limits<streamsize>::max(), '\n');  // FIX

//         // ================= POSTS =================
//         for (int j = 0; j < postCount; j++) {

//             int postID, authorId, votes;
//             string text;

//             file >> postID;
//             file.ignore(numeric_limits<streamsize>::max(), '\n');

//             file >> authorId;
//             file.ignore(numeric_limits<streamsize>::max(), '\n');

//             file >> votes;
//             file.ignore(numeric_limits<streamsize>::max(), '\n');

//             getline(file, text);  // safe now

//             // find author
//             User* author = nullptr;
//             for (auto u : users)
//                 if (u->getId() == authorId)
//                     author = u;

//             Post* post = new Post(text, author, postID, votes);

//             // ================= COMMENTS =================
//             int commentCount;
//             file >> commentCount;
//             file.ignore(numeric_limits<streamsize>::max(), '\n');  // FIX

//             for (int k = 0; k < commentCount; k++) {

//                 int commentID, authorID;
//                 string authorName, commentText;

//                 file >> commentID;
//                 file.ignore(numeric_limits<streamsize>::max(), '\n');

//                 file >> authorID;
//                 file.ignore(numeric_limits<streamsize>::max(), '\n');

//                 getline(file, authorName);
//                 getline(file, commentText);

//                 post->addComment(
//                     new Comment(commentText, authorID, authorName, commentID)
//                 );
//             }

//             // ================= UPVOTES =================
//             int upCount;
//             file >> upCount;

//             for (int k = 0; k < upCount; k++) {
//                 int userID;
//                 file >> userID;
//                 post->addUpvotedUser(userID);
//             }
//             file.ignore(numeric_limits<streamsize>::max(), '\n');  // FIX

//             // ================= DOWNVOTES =================
//             int downCount;
//             file >> downCount;

//             for (int k = 0; k < downCount; k++) {
//                 int userID;
//                 file >> userID;
//                 post->addDownvotedUser(userID);
//             }
//             file.ignore(numeric_limits<streamsize>::max(), '\n');  // FIX

//             comm->addPost(post);
//         }
//     }
// }



































#include "FileManager.h"
#include <fstream>
#include <limits>

using namespace std;

// ================= SAVE =================
void saveData(SystemManager* sys) {
    ofstream file("data.txt");

    auto& users = sys->getUsers();
    auto& comms = sys->getCommunities();

    // ================= USERS =================
    file << "USERS " << users.size() << endl;
    for (auto u : users) {
        file << u->getId() << " "
             << u->getUsername() << " "
             << u->getPassword() << endl;
    }

    // ================= COMMUNITIES =================
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

            // COMMENTS
            auto& comments = p->getComments();
            file << "COMMENTS " << comments.size() << endl;

            for (auto cmt : comments) {
                file << "COMMENT " << cmt->getId() << endl;
                file << "C_AUTHOR_ID " << cmt->getAuthorId() << endl;
                file << "C_AUTHOR_NAME " << cmt->getAuthorName() << endl;
                file << "C_TEXT " << cmt->getText() << endl;
            }

            // VOTES
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

// ================= LOAD =================
void loadData(SystemManager* sys) {
    ifstream file("data.txt");
    if (!file) return;

    auto& users = sys->getUsers();
    auto& comms = sys->getCommunities();

    users.clear();
    comms.clear();

    string label;

    // ================= USERS =================
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

    // ================= COMMUNITIES =================
    int commCount;
    file >> label >> commCount;
    file.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < commCount; i++) {

        // COMMUNITY name
        string name;
        file >> label; // COMMUNITY
        file.ignore(); // skip space
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

            file >> label; // TEXT
            file.ignore();
            getline(file, text);

            // find author
            User* author = nullptr;
            for (auto u : users)
                if (u->getId() == authorId)
                    author = u;

            Post* post = new Post(text, author, postID, votes);

            // COMMENTS
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

            // UPVOTES
            int upCount;
            file >> label >> upCount;

            for (int k = 0; k < upCount; k++) {
                int id;
                file >> id;
                post->addUpvotedUser(id);
            }
            file.ignore(numeric_limits<streamsize>::max(), '\n');

            // DOWNVOTES
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