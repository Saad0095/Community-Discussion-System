#include <iostream>
#include "SystemManager.h"
#include "FileManager.h"

using namespace std;

int main()
{
    SystemManager *sys = SystemManager::getInstance();

    loadData(sys);

    auto &users = sys->getUsers();
    auto &comms = sys->getCommunities();

    if (comms.empty())
        comms.push_back(new Community("General"));

    User *currentUser = nullptr;
    int choice;

    while (true)
    {
        try
        {
            cout << "\n1.Register 2.Login 3.Create Community 4.View Communities\n";
            cout << "5.Create Post 6.View Posts 7.Comment 8.Delete Post 9.Delete Comment\n";
            cout << "10.Upvote 11.Downvote 12.Save&Exit\nChoice: ";

            cin >> choice;

            if (choice == 1)
            {
                string userName, password;
                cout << "Username: ";
                cin >> userName;
                cout << "Password: ";
                cin >> password;

                for (auto x : users)
                    if (x->getUsername() == userName)
                        throw runtime_error("Username exists!");

                users.push_back(new User(userName, password));
                cout << "Registered!\n";
            }

            else if (choice == 2)
            {
                string userName, password;
                cout << "Username: ";
                cin >> userName;
                cout << "Password: ";
                cin >> password;

                bool found = false;
                for (auto x : users)
                {
                    if (x->login(userName, password))
                    {
                        currentUser = x;
                        found = true;
                        cout << "Login success\n";
                        break;
                    }
                }
                if (!found)
                    throw runtime_error("Invalid credentials!");
            }

            else if (choice >= 3 && choice <= 11 && !currentUser)
                throw runtime_error("Login first!");

            else if (choice == 3)
            {
                string communityName;
                cout << "Community name: ";
                cin >> communityName;
                comms.push_back(new Community(communityName));
            }

            else if (choice == 4)
            {
                for (int i = 0; i < comms.size(); i++)
                    cout << i << "." << comms[i]->getName() << endl;
            }

            else if (choice == 5)
            {
                int communityIndex;
                cout << "Community index: ";
                cin >> communityIndex;
                cin.ignore();

                string communityTitle;
                cout << "Post text: ";
                getline(cin, communityTitle);

                comms.at(communityIndex)->addPost(currentUser->createPost(communityTitle));
            }

            else if (choice == 6)
            {
                for (auto c : comms)
                    c->displayPosts();
            }

            else if (choice == 7)
            {
                int communityIndex, postIndex;
                cout << "Community index & Post index: ";
                cin >> communityIndex >> postIndex;
                cin.ignore();

                string t;
                cout << "Comment: ";
                getline(cin, t);

                comms.at(communityIndex)
                    ->getPosts()
                    .at(postIndex)
                    ->addComment(
                        new Comment(t, currentUser->getId(), currentUser->getUsername()));
            }

            else if (choice == 8)
            {
                int communityIndex, postID;
                cout << "Community index & Post ID: ";
                cin >> communityIndex >> postID;

                comms.at(communityIndex)->deletePost(postID, currentUser->getId());
            }

            else if (choice == 9)
            {
                int communityIndex, postIndex, commentID;
                cout << "Community index, Post index, Comment ID: ";
                cin >> communityIndex >> postIndex >> commentID;

                comms.at(communityIndex)->getPosts().at(postIndex)->deleteComment(commentID, currentUser->getId());
            }

            else if (choice == 10)
            {
                int communityIndex, postIndex;
                cout << endl
                     << "Enter Community Index";
                cin >> communityIndex;
                cout << endl
                     << "Enter Post Index";
                cin >> postIndex;

                comms.at(communityIndex)->getPosts().at(postIndex)->upvote(currentUser);
            }

            else if (choice == 11)
            {
                int communityIndex, postIndex;
                cin >> communityIndex >> postIndex;

                comms.at(communityIndex)->getPosts().at(postIndex)->downvote(currentUser);
            }

            else if (choice == 12)
            {
                saveData(sys);
                cout << "Saved!\n";
                break;
            }

            else
            {
                throw runtime_error("Invalid choice!");
            }
        }
        catch (exception &e)
        {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}