# Community Discussion System

A console-based discussion platform built in C++ to demonstrate how object-oriented design can be applied to a realistic social interaction system. The project models core forum-style features such as communities, posts, comments, voting, authentication, and file-based persistence in a clean academic OOP setting.

## Overview

The Community Discussion System is inspired by platforms like Reddit and traditional online forums, where users gather around shared interests, publish posts, discuss ideas, and engage through feedback. This implementation focuses on translating those interactions into a structured C++ application using classes, inheritance, composition, polymorphism, templates, and basic persistence.

The project is designed for learning as much as functionality. It highlights how separate objects collaborate to represent users, content, communities, and system-level management while keeping responsibilities organized and maintainable.

## Key Features

- User registration and login
- Community creation and browsing
- Post creation inside communities
- Commenting on posts
- Upvoting and downvoting posts
- Deletion of a user's own posts and comments
- Automatic ID generation for users, posts, and comments
- File-based save and load functionality

## Project Structure

- `User` manages authentication data and post creation.
- `Community` stores and manages collections of posts.
- `Post` represents discussion entries, voting, and comments.
- `Comment` represents user replies on posts.
- `Content` acts as the abstract base class for shared content behavior.
- `SystemManager` centralizes users and communities using the Singleton pattern.
- `FileManager` handles persistence to and from `data.txt`.
- `IDGenerator` provides template-based unique ID generation.

## OOP Concepts Demonstrated

### Encapsulation

Each class keeps its internal state private or protected and exposes behavior through public member functions such as getters, creation methods, and controlled updates.

### Inheritance

`Post` and `Comment` inherit from the `Content` base class, reusing shared properties like `id` and `votes`.

### Polymorphism

The `display()` function is declared virtual in `Content` and overridden in derived classes, allowing posts and comments to define their own presentation.

### Abstraction

`Content` serves as an abstract representation of platform content, exposing only the common interface needed by derived classes.

### Composition

- A `Community` contains many `Post` objects.
- A `Post` contains many `Comment` objects.

### Association

A `Post` is associated with a `User` as its author.

### Templates

The `IDGenerator` template creates separate ID counters for different entity types.

## System Workflow

1. The application starts and loads saved data from `data.txt`.
2. Users can register or log in.
3. Logged-in users can create communities, publish posts, and add comments.
4. Users can interact with posts through upvotes and downvotes.
5. Users may delete their own posts or comments.
6. The system saves all data before exit.

## Design Pattern

### Singleton Pattern

`SystemManager` is implemented as a Singleton to ensure that only one central manager controls all users and communities throughout the program lifecycle.

## Data Persistence

The application uses file-based storage through `FileManager`. User data, communities, posts, comments, and voting information are written to `data.txt` and restored when the program runs again. This makes the system easy to test and portable without requiring a database.

## How to Build and Run

Compile all `.cpp` files together using a C++ compiler such as `g++`.

```bash
g++ main.cpp User.cpp Post.cpp Comment.cpp Community.cpp Content.cpp FileManager.cpp SystemManager.cpp -o app
```

Run the executable:

```bash
./app
```

On Windows with MinGW:

```bash
g++ main.cpp User.cpp Post.cpp Comment.cpp Community.cpp Content.cpp FileManager.cpp SystemManager.cpp -o app.exe
app.exe
```

## Current Limitations

- Uses plain text file storage instead of a database
- Stores passwords without encryption
- Console interface only
- Basic validation and error handling suitable for academic use, not production deployment

## Future Enhancements

- Replace file storage with a database backend
- Add stronger authentication and password hashing
- Introduce a graphical user interface
- Improve search, filtering, and moderation features
- Expand input validation and user experience

## Contributors

- Muhammad Saad Bin Khalid
- Abdullah Bin Waqar
- Hassaan Ahmed Khan
- Muhammad Mujtaba Fakih
