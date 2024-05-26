#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include "task.h"

using namespace std;

class ToDoList {
private:
    Task* head;

public:
    // Constructor
    ToDoList();

    // Destructor
    ~ToDoList();

    // Function to add a new task to the list
    void addTask(const std::string& description);

    // Function to remove a task from the list by index
    void removeTask(int index);

    // Function to display the To-Do List
    void displayTasks() const;

    // Function to check if a task is done by index
    bool isTaskDone(int index) const;

    // Function to mark a task as done by index
    void markTaskDone();

    // Function to edit the description of a task
    void editTaskDescription(int index);

    // Function to show done tasks
    void showDoneTasks() const;

    // Function to show removed tasks
    void showRemovedTasks() const;

    // Function to return a removed task by index
    void returnRemovedTask(int index);

    // Function to return a done task to not done
    void returnDoneTask();

    // Function to clear all tasks
    void clearAllTasks();
};

#endif
