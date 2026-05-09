# 🚀 Community Discussion System

> A feature-rich **console-based forum platform** built with **C++ and Object-Oriented Programming**, inspired by platforms like Reddit and traditional discussion boards.

This project demonstrates how real-world social interaction systems can be modeled using clean OOP architecture, reusable components, and structured system design.

---

## 📌 Project Overview

The **Community Discussion System** simulates an online discussion platform where users can:

- Create communities
- Publish posts
- Engage through comments
- Vote on content
- Manage discussions

The primary goal of this project is to showcase how core **Object-Oriented Programming principles** can be applied to build a scalable and maintainable application in C++.

It combines:

- 🧠 Academic OOP concepts
- 🏗️ Real-world system design
- 💾 File-based persistence
- ⚙️ Structured architecture
- 📚 Clean separation of responsibilities

---

# ✨ Features

## 👤 User System
- User registration and login
- Authentication handling
- User-specific content management

## 🌐 Community Management
- Create and browse communities
- Organize discussions by topic

## 📝 Posts & Discussions
- Create posts inside communities
- Add comments to posts
- Delete your own posts and comments

## 👍 Voting System
- Upvote posts
- Downvote posts
- Track engagement through votes

## 🆔 Smart ID Generation
- Automatic unique IDs for:
  - Users
  - Posts
  - Comments

## 💾 Data Persistence
- Save all application data into `data.txt`
- Reload data automatically on startup

---

# 🏗️ System Architecture

The project is organized into multiple classes with clear responsibilities.

| Class | Responsibility |
|---|---|
| `User` | Handles authentication and user actions |
| `Community` | Manages collections of posts |
| `Post` | Represents discussion posts and voting |
| `Comment` | Represents replies on posts |
| `Content` | Abstract base class for shared content behavior |
| `SystemManager` | Centralized system controller (Singleton) |
| `FileManager` | Handles file save/load operations |
| `IDGenerator` | Template-based unique ID generation |

---

# 🧠 OOP Concepts Demonstrated

## 🔒 Encapsulation
Each class protects its internal state and exposes controlled behavior through public methods.

## 🧬 Inheritance
`Post` and `Comment` inherit from the abstract `Content` class.

## 🎭 Polymorphism
The `display()` method is overridden in derived classes to provide custom output behavior.

## 🧩 Abstraction
`Content` defines a common interface for all platform content.

## 🧱 Composition
- A `Community` contains multiple `Post` objects
- A `Post` contains multiple `Comment` objects

## 🔗 Association
Posts are associated with their authors (`User`).

## 🧮 Templates
`IDGenerator<T>` uses templates for reusable ID management across entities.

---

# 🔄 Application Workflow

```text
Start Application
        ↓
Load Saved Data
        ↓
Register / Login
        ↓
Create or Browse Communities
        ↓
Create Posts & Comments
        ↓
Vote & Interact
        ↓
Save Data Before Exit
```

---

# 🎯 Design Pattern Used

## Singleton Pattern

`SystemManager` is implemented using the **Singleton Pattern** to ensure only one global system controller exists throughout the application lifecycle.

---

# 💾 Data Persistence

The application uses a simple **file-based storage system** through `FileManager`.

All users, communities, posts, comments, and voting information are stored inside:

```bash
data.txt
```

This makes the project:

- Lightweight
- Portable
- Easy to test
- Beginner-friendly

without requiring a database setup.

---

# ⚙️ How to Build & Run

## 🔨 Compile (Linux/macOS)

```bash
g++ main.cpp User.cpp Post.cpp Comment.cpp Community.cpp Content.cpp FileManager.cpp SystemManager.cpp -o app
```

## ▶️ Run

```bash
./app
```

---

## 🪟 Windows (MinGW)

### Compile

```bash
g++ main.cpp User.cpp Post.cpp Comment.cpp Community.cpp Content.cpp FileManager.cpp SystemManager.cpp -o app.exe
```

### Run

```bash
app.exe
```

---

# 📂 Example Project Structure

```text
📦 Community-Discussion-System
 ┣ 📜 main.cpp
 ┣ 📜 User.cpp
 ┣ 📜 Community.cpp
 ┣ 📜 Post.cpp
 ┣ 📜 Comment.cpp
 ┣ 📜 Content.cpp
 ┣ 📜 FileManager.cpp
 ┣ 📜 SystemManager.cpp
 ┣ 📜 data.txt
 ┗ 📜 README.md
```

---

# ⚠️ Current Limitations

- Console-based interface only
- Uses plain text storage instead of a database
- Passwords are not encrypted
- Basic validation and error handling
- Designed primarily for learning and academic demonstration

---

# 🚀 Future Improvements

- Replace file storage with a database system
- Add password hashing & stronger authentication
- Build a GUI or web-based interface
- Improve moderation and search functionality
- Add better validation and error handling
- Introduce real-time interactions

---

# 📚 Learning Outcomes

This project is ideal for understanding:

- Object-Oriented Programming in C++
- System architecture design
- Class relationships
- File handling
- Data persistence
- Scalable code organization
- Design patterns in real applications

---

# 👨‍💻 Contributors

- **Muhammad Saad Bin Khalid**
- **Abdullah Bin Waqar**
- **Hassaan Ahmed Khan**
- **Muhammad Mujtaba Fakih**

---

# ⭐ Final Note

This project was built as a practical demonstration of how **real-world social platforms** can be translated into a structured C++ application using strong **OOP principles** and clean software design.

If you found this project helpful or interesting, consider giving it a ⭐ on GitHub.