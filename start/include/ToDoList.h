#ifndef TODOLIST_H
#define TODOLIST_H

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ToDoList : public QWidget {
    Q_OBJECT

public:
    explicit ToDoList(QWidget *parent = nullptr);

private slots:
    void addTask();
    void removeTask(QListWidgetItem *item);

private:
    QLineEdit *taskInput;
    QPushButton *addButton;
    QListWidget *taskList;
};

#endif // TODOLIST_H
