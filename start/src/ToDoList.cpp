#include "ToDoList.h"

ToDoList::ToDoList(QWidget *parent) : QWidget(parent) {
    setWindowTitle("To-Do List");

    taskInput = new QLineEdit(this);
    addButton = new QPushButton("Add", this);
    taskList = new QListWidget(this);

    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(taskInput);
    inputLayout->addWidget(addButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(taskList);
    setLayout(mainLayout);

    connect(addButton, &QPushButton::clicked, this, &ToDoList::addTask);
    connect(taskInput, &QLineEdit::returnPressed, this, &ToDoList::addTask);
    connect(taskList, &QListWidget::itemDoubleClicked, this, &ToDoList::removeTask);
}

void ToDoList::addTask() {
    QString task = taskInput->text().trimmed();
    if (!task.isEmpty()) {
        taskList->addItem(task);
        taskInput->clear();
    }
}

void ToDoList::removeTask(QListWidgetItem *item) {
    delete item;
}
