#include <QApplication>
#include "ToDoList.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ToDoList window;
    window.resize(400, 300);
    window.show();
    return app.exec();
}
