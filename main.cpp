#include "FileManager.h"
#include "SystemManager.h"
#include <iostream>

using namespace std;

int main() {
  SystemManager *sys = SystemManager::getInstance();

  loadData(sys);

  auto &users = sys->getUsers();
  auto &comms = sys->getCommunities();

  cout << "\n** Welcome To Community Discussion System **\n";

  if (comms.empty())
    comms.push_back(new Community("General"));

  User *currentUser = nullptr;
  int choice;

  while (true) {
    try {
      cout << "\n====================================\n";

      if (currentUser)
        cout << "Logged in as: " << currentUser->getUsername() << endl;
      else
        cout << "Not Logged In\n";

      cout << "====================================\n";
      cout << "\nSelct any of the below options:\n";
      cout << "1. Register\n";
      cout << "2. Login\n";
      cout << "3. Create Community\n";
      cout << "4. View Communities\n";
      cout << "5. Create Post\n";
      cout << "6. View Posts\n";
      cout << "7. Add Comment\n";
      cout << "8. Delete Post\n";
      cout << "9. Delete Comment\n";
      cout << "10. Upvote Post\n";
      cout << "11. Downvote Post\n";
      cout << "12. View My Posts\n";
      cout << "13. Save & Exit\n";
      cout << "14. Logout\n";
      cout << "==========================\n";
      cout << "Choice: ";

      cin >> choice;

      if (choice == 1) {
        string userName, password;
        cout << "Username: ";
        cin >> userName;
        cout << "Password: ";
        cin >> password;

        for (auto x : users)
          if (x->getUsername() == userName)
            throw runtime_error("Username exists!");

        users.push_back(new User(userName, password));
        cout << "User registered successfully!" << endl;
      }

      else if (choice == 2) {
        string userName, password;
        cout << "Username: ";
        cin >> userName;
        cout << "Password: ";
        cin >> password;

        bool found = false;
        for (auto x : users) {
          if (x->login(userName, password)) {
            currentUser = x;
            found = true;
            cout << "Login success" << endl;
            cout << "Welcome, " << currentUser->getUsername() << "!" << endl;
            break;
          }
        }
        if (!found)
          throw runtime_error("Invalid credentials!");
      }

      else if ((choice == 3 || choice == 5 || choice == 7 || choice == 8 ||
                choice == 9 || choice == 10 || choice == 11 || choice == 12 ||
                choice == 14) &&
               !currentUser)
        throw runtime_error("Please login first!");

      else if (choice == 3) {
        string communityName;
        cout << "Community name: ";
        cin.ignore();
        getline(cin, communityName);
        comms.push_back(new Community(communityName));
        cout << "Community created successfully!\n";
      }

      else if (choice == 4) {
        if (comms.empty()) {
          cout << "No communities found.\n";
        } else {
          for (int i = 0; i < comms.size(); i++) {
            cout << i << ". " << comms[i]->getName() << endl;
          }
        }
      }

      else if (choice == 5) {
        int communityIndex;
        cout << "Community index: ";
        cin >> communityIndex;
        cin.ignore();

        string communityTitle;
        cout << "Post text: ";
        getline(cin, communityTitle);

        comms.at(communityIndex)
            ->addPost(currentUser->createPost(communityTitle));
        cout << "Post created successfully!" << endl;
      }

      else if (choice == 6) {
        for (auto c : comms)
          c->displayPosts();
      }

      else if (choice == 7) {
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
            ->addComment(new Comment(t, currentUser->getId(),
                                     currentUser->getUsername()));
        cout << "Comment added successfully!\n";
      }

      else if (choice == 8) {
        int communityIndex, postID;
        cout << "Community index & Post index: ";
        cin >> communityIndex >> postID;

        comms.at(communityIndex)->deletePost(postID, currentUser->getId());
        cout << "Post deleted successfully!\n";
      }

      else if (choice == 9) {
        int communityIndex, postIndex, commentID;
        cout << "Community index, Post index, Comment ID: ";
        cin >> communityIndex >> postIndex >> commentID;

        comms.at(communityIndex)
            ->getPosts()
            .at(postIndex)
            ->deleteComment(commentID, currentUser->getId());
        cout << "Comment deleted successfully!\n";
      }

      else if (choice == 10) {
        int communityIndex, postIndex;
        cout << endl << "Enter Community Index: ";
        cin >> communityIndex;
        cout << endl << "Enter Post Index: ";
        cin >> postIndex;

        comms.at(communityIndex)->getPosts().at(postIndex)->upvote(currentUser);
        cout << "Post upvoted successfully!\n";
      }

      else if (choice == 11) {
        int communityIndex, postIndex;
        cout << endl << "Enter Community Index: ";
        cin >> communityIndex;
        cout << endl << "Enter Post Index: ";
        cin >> postIndex;

        comms.at(communityIndex)
            ->getPosts()
            .at(postIndex)
            ->downvote(currentUser);
        cout << "Post downvoted successfully!\n";
      }

      else if (choice == 12) {
        bool found = false;

        cout << "\nMy Posts:\n";

        for (auto c : comms) {
          for (auto p : c->getPosts()) {
            if (p->getAuthor() &&
                p->getAuthor()->getId() == currentUser->getId()) {
              cout << "\nCommunity: " << c->getName() << endl;

              p->display();

              found = true;
            }
          }
        }

        if (!found) {
          cout << "You have not created any posts yet.\n";
        }
      } else if (choice == 13) {
        saveData(sys);
        cout << "Saved!\n";
        return 0;
      } else if (choice == 14) {
        currentUser = nullptr;
        cout << "Logged out successfully!\n";
      }

      else {
        throw runtime_error("Invalid choice!");
      }
    } catch (exception &e) {
      cout << "Error: " << e.what() << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }
  }
}