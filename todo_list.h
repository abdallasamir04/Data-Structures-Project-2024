#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <list>
#include "task.h"

// Class representing a to-do list
class ToDoList {
private:
    std::list<Task> tasks;          // List of tasks
    std::list<Task> removedTasks;   // List of removed tasks
    std::list<Task> doneTasks;      // List of done tasks

public:
    // Function to add a task
    void addTask(const std::string& description);

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

    // Function to return a done task to not done
    void returnDoneTask();

    // Function to clear all tasks
    void clearAllTasks();

    // Function to show all not done tasks
    void showNotDoneTasks() const;

    // Function to count the number of tasks
    int countTasks() const;
};

#endif // TODO_LIST_H
