# Exercise: Multi-Widget Qt App – To-Do List

## Introduction

In this exercise, you’ll implement a **multi-widget Qt application** using **Qt and CMake**, fulfilling the following core requirements:

- Use of **at least three Qt widgets**

- A **layout manager** to organize them

- A **working signal-slot connection** for interactivity

To meet these criteria, you will build a functional **To-Do List desktop app**. The app will allow users to add and remove tasks, with clean UI layout and proper event handling using Qt’s signal-slot system — all implemented in **C++**.

---

## **Working with Dev Container**

To complete this assignment in a reliable and fully configured environment, please refer to the instructions in the file: **`README-devcontainer.md`**. This guide walks you through opening the assignment in **Visual Studio Code** using a **Dev Container**, which automatically installs all necessary Python libraries and tools. Following that setup ensures that the notebook runs smoothly without manual configuration or missing dependencies. Make sure to open the **main assignment folder** in VS Code and follow the steps outlined in the Dev Container guide before starting the notebook.

----

### Prerequisites

* Qt 6 (Widgets module) and CMake installed.
* Qt Creator (or another code editor) set up with a desktop Qt GCC kit.
* Comfort with basic C++ syntax and navigating a terminal.

### Starter Files

`start` direcory contains `ToDoApp` folder that has the following structure 

```
ToDoApp/
├── CMakeLists.txt         # empty build script to fill in
├── Forms/
│   └── todolist.ui        # blank Designer form (choose QWidget when adding)
├── include/
│   └── ToDoList.h         # empty header for your class
└── src/
    ├── ToDoList.cpp       # empty source for UI setup & logic
    └── main.cpp           # empty entry point
```

Use Add New → Qt Designer Form Class in Qt Creator to generate `todolist.ui`, `ToDoList.h`, and `ToDoList.cpp` stubs. Leave them empty for now.

---

## Requirements

### 1. Project Setup

* Populate `CMakeLists.txt` so that:
  * It finds Qt6 Widgets.
  * It runs `uic` on `Forms/todolist.ui`.
  * It compiles and links your headers and sources into an executable.

### 2. UI Design

* In todolist.ui, apply a QVBoxLayout to the top-level widget.
* Add, in order:
  1. QLineEdit named `taskEdit` with placeholder "Enter new task…".
  2. QPushButton named `addButton` with text "Add Task".
  3. QListWidget named `taskList`.
* Preview to confirm a neat vertical stack.

### 3. Widget Class

* In include/ToDoList.h, declare a class `ToDoList : public QWidget` with:
  * A pointer `Ui::ToDoList *ui;`
  * Slots `void addTask();` and `void removeTask(QListWidgetItem*);`

### 4. Signal-Slot Logic

* In src/ToDoList.cpp constructor:
  * Call `ui->setupUi(this);`
  * Connect `addButton.clicked` and `taskEdit.returnPressed` to `addTask()`.
  * Connect `taskList.itemDoubleClicked` to `removeTask(QListWidgetItem*)`.
* Implement `addTask()` to:
  * Read and trim text from `taskEdit`.
  * Ignore empty input.
  * Append a new item to `taskList`.
  * Clear `taskEdit`.
* Implement `removeTask(item)` to delete the passed `QListWidgetItem`, removing it from the list.

### 5. Entry Point

* In src/main.cpp, create a `QApplication`, instantiate `ToDoList`, set its window title, show it, and call `app.exec()`.

---

## Deliverables

1. Source Folder (ToDoApp/) containing:
   * CMakeLists.txt correctly configured.
   * Forms/todolist.ui, include/ToDoList.h, src/ToDoList.cpp, src/main.cpp fully implemented.
2. Build Instructions in a brief README.md:
   * How to configure and build (`mkdir build`, `cmake ..`, `make`).
   * How to run (`./ToDoApp`).
3. Code Comments explaining:
   * Why you call `setupUi(this)`.
   * How each signal-slot connection works.
   * How deleting a `QListWidgetItem` removes it safely.

---

## Success Criteria

* Build & Run: App compiles cleanly and launches without errors.
* UI Layout: Three widgets in a vertical stack, matching the design.
* Interactivity:
  * Typing a task + Enter or clicking "Add Task" appends it.
  * Double-clicking a list item removes it immediately.
* Code Quality: Clear, concise, and well-organized across CMake, UI form, headers, and sources.
* Memory Safety: Qt's parent-child model handles widget cleanup; deleting list items frees memory without leaks.

## Conclusion

You've now built a lean, fully functional To-Do List app in Qt and C++. You set up CMake to process your .ui file, designed a clean vertical layout in Designer, and wrote just enough code to let users add tasks with Enter or a button click—and remove them with a double-click. This exercise reinforces the essentials of Qt: form design, signals and slots, and memory-safe widget ownership. Enjoy expanding this foundation into richer, more feature-packed applications!
