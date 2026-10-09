cmake_minimum_required(VERSION 3.16)
project(ToDoApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ToDoApp
    src/main.cpp
    src/ToDoList.cpp
    include/ToDoList.h
    Forms/todolist.ui
)

target_link_libraries(ToDoApp PRIVATE Qt6::Widgets)
