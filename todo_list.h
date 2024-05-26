#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <list>
#include "task.h"

using namespace std;

// Class representing a to-do list
class ToDoList {
private:
    list<Task> tasks;          // List of tasks
    list<Task> removedTasks;   // List of removed tasks
    list<Task> doneTasks;      // List of done tasks

public:
    // Function to add a task
    void addTask(const string& description);

    // Function to remove a task by index
    void removeTask(int index);

    // Function to display all tasks
    void displayTasks() const;

    // Function to mark a task as done
    void markTaskDone();

    // Function to edit a task description by index
    void editTaskDescription(int index);

    // Function to show all done tasks
    void showDoneTasks() const;

    // Function to show all removed tasks
    void showRemovedTasks() const;

    // Function to return a removed task by index
    void returnRemovedTask(int index);

    // Function to return a done task to not done status
    void returnDoneTask();

    // Function to clear all tasks
    void clearAllTasks();

    // Function to show all not done tasks
    void showNotDoneTasks() const;

    // Function to count the number of tasks
    int countTasks() const;

    // Function to check if a task is done by index
    void checkTaskDone(int index) const;
};

#endif // TODO_LIST_H
