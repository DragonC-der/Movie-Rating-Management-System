
# 🎬 Movie Rating Management System

A **C++ console-based application** that manages movies based on their ratings using a **Binary Search Tree (BST)**.
The system allows users to add movies, delete movies, and view movies grouped by ratings with efficient searching and ordering.

This project demonstrates the use of **data structures, input validation, and memory management** in C++.

---

# 📌 Features

* ➕ Add movies with ratings (0–10)
* 🗑 Delete a movie from a specific rating
* 📊 Display all movies sorted by rating
* 🔽 View movies with the **minimum rating**
* 🔼 View movies with the **maximum rating**
* 🚫 Prevent duplicate movie entries
* ✅ Robust input validation for numbers, characters, and strings
* 📈 Track:

  * Total ratings
  * Total movies

---

# 🧠 Data Structures Used

| Data Structure                | Purpose                                                      |
| ----------------------------- | ------------------------------------------------------------ |
| **Binary Search Tree (BST)**  | Stores ratings as nodes for efficient searching and ordering |
| **Vector<string>**            | Stores movies under the same rating                          |
| **unordered_map<string,int>** | Prevents duplicate movie entries                             |
| **Recursion**                 | Used for traversal, searching, and deletion                  |

---

# 🏗 System Design

Each **BST node** represents a **rating**.

```
Node
 ├── rating (double)
 ├── vector<string> movies
 ├── left
 └── right
```

Example structure:

```
        8.5
       /   \
     7.0   9.2
    /         \
  6.5         9.8
```

Each rating node stores **multiple movies with the same rating**.

---

# ⚙️ Core Functionalities

## 1️⃣ Add Movie

* Enter rating
* If rating exists → movie added to that node
* If rating does not exist → new BST node created

---

## 2️⃣ Delete Movie

* Search rating
* Display movies under that rating
* Delete selected movie
* If no movies remain → delete the BST node

---

## 3️⃣ Display All Movies

Uses **In-order traversal** of BST to show movies sorted by rating.

---

## 4️⃣ Minimum Rating

Finds the **leftmost node** in BST.

---

## 5️⃣ Maximum Rating

Finds the **rightmost node** in BST.

---

# 🛡 Input Validation

The system prevents invalid inputs such as:

| Input Type  | Validation                   |
| ----------- | ---------------------------- |
| Rating      | Must be between **0 and 10** |
| Movie count | Must be **1–20**             |
| Menu option | Must be a valid number       |
| Characters  | Handles invalid input safely |

Example logic:

```
cin.fail()
cin.clear()
cin.ignore()
```

This ensures the program **never crashes due to incorrect user input**.

---

# ▶️ How to Run

### 1️⃣ Clone the repository

```bash
git clone https://github.com/DragonC-der/movie-rating-management-system.git
```

---

### 2️⃣ Compile the program

```bash
g++ main.cpp -o movie_system
```

---

### 3️⃣ Run the program

```bash
./movie_system
```

---

# 🖥 Example Menu

```
Movie Rating Management System

1. Add a movie
2. Delete a movie
3. Show all movie ratings
4. Minimum rating movie(s)
5. Maximum rating movie(s)
6. Exit
```

---

# 📂 Project Structure

```
Movie-Rating-Management-System/
│
├── src/main.cpp              # source code of the project
├──.gitignore.txt
└── README.md             # Project documentation
```

---

# 🚀 Future Improvements

Possible enhancements:

* 🔍 Search movie by name
* ⭐ Update movie rating
* 📁 File storage (save/load movies)
* 🖥 GUI interface
* 🌐 REST API backend version
* ⚡ Self-balancing tree (AVL / Red-Black Tree)

---

# 🎯 Learning Outcomes

Through this project:

* Implemented **Binary Search Tree operations**
* Practiced **recursion and dynamic memory management**
* Built **robust input validation**
* Designed a **simple data management system**

---
