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
                string u, p;
                cout << "Username: ";
                cin >> u;
                cout << "Password: ";
                cin >> p;

                for (auto x : users)
                    if (x->getUsername() == u)
                        throw runtime_error("Username exists!");

                users.push_back(new User(u, p));
                cout << "Registered!\n";
            }

            else if (choice == 2)
            {
                string u, p;
                cout << "Username: ";
                cin >> u;
                cout << "Password: ";
                cin >> p;

                bool found = false;
                for (auto x : users)
                {
                    if (x->login(u, p))
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
                string n;
                cout << "Community name: ";
                cin >> n;
                comms.push_back(new Community(n));
            }

            else if (choice == 4)
            {
                for (int i = 0; i < comms.size(); i++)
                    cout << i << "." << comms[i]->getName() << endl;
            }

            else if (choice == 5)
            {
                int ci;
                cout << "Community index: ";
                cin >> ci;
                cin.ignore();

                string t;
                cout << "Post text: ";
                getline(cin, t);

                comms.at(ci)->addPost(currentUser->createPost(t));
            }

            else if (choice == 6)
            {
                for (auto c : comms)
                    c->displayPosts();
            }

            else if (choice == 7)
            {
                int ci, pi;
                cout << "Community index & Post index: ";
                cin >> ci >> pi;
                cin.ignore();

                string t;
                cout << "Comment: ";
                getline(cin, t);

                comms.at(ci)
                    ->getPosts()
                    .at(pi)
                    ->addComment(
                        new Comment(t, currentUser->getId(), currentUser->getUsername()));
            }

            else if (choice == 8)
            {
                int ci, pid;
                cout << "Community index & Post ID: ";
                cin >> ci >> pid;

                comms.at(ci)->deletePost(pid, currentUser->getId());
            }

            else if (choice == 9)
            {
                int ci, pi, cid;
                cout << "Community index, Post index, Comment ID: ";
                cin >> ci >> pi >> cid;

                comms.at(ci)->getPosts().at(pi)->deleteComment(cid, currentUser->getId());
            }

            else if (choice == 10)
            {
                int ci, pi;
                cout << endl
                     << "Enter Community Index";
                cin >> ci;
                cout << endl
                     << "Enter Post Index";
                cin >> pi;

                comms.at(ci)->getPosts().at(pi)->upvote(currentUser);
            }

            else if (choice == 11)
            {
                int ci, pi;
                cin >> ci >> pi;

                comms.at(ci)->getPosts().at(pi)->downvote(currentUser);
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