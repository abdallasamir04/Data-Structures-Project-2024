#include "todo_list.h"
#include <iostream>

using namespace std;

// Add a task to the to-do list
void ToDoList::addTask(const std::string& description) {
    tasks.emplace_back(description);
}

// Remove a task by index
void ToDoList::removeTask(int index) {
    if (index <= 0 || index > tasks.size()) {
        cout << "Invalid index.\n";
        return;
    }
    auto it = tasks.begin();
    advance(it, index - 1);
    removedTasks.push_back(*it);
    tasks.erase(it);
}

// Display all tasks with their status
void ToDoList::displayTasks() const {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "Current To-Do List:\n";
    int i = 1;
    for (const auto& task : tasks) {
        cout << i << ". " << task.getDescription() << (task.isDone() ? " (Done)" : " (Not Done)") << endl;
        i++;
    }
}

// Mark a task as done by index
void ToDoList::markTaskDone() {
    displayTasks();
    if (tasks.empty()) return;

    int index;
    cout << "Enter the index of the task to mark as done: ";
    cin >> index;
    if (index <= 0 || index > tasks.size()) {
        cout << "Invalid index.\n";
        return;
    }
    auto it = tasks.begin();
    advance(it, index - 1);
    it->markDone();
    doneTasks.push_back(*it);
}

// Edit a task description by index
void ToDoList::editTaskDescription(int index) {
    if (index <= 0 || index > tasks.size()) {
        cout << "Invalid index.\n";
        return;
    }
    auto it = tasks.begin();
    advance(it, index - 1);
    string newDescription;
    cout << "Enter new description: ";
    cin.ignore();
    getline(cin, newDescription);
    it->setDescription(newDescription);
}

// Show all tasks marked as done
void ToDoList::showDoneTasks() const {
    if (doneTasks.empty()) {
        cout << "No done tasks.\n";
        return;
    }
    cout << "Done Tasks:\n";
    int i = 1;
    for (const auto& task : doneTasks) {
        cout << i << ". " << task.getDescription() << " (Done)" << endl;
        i++;
    }
}

// Show all removed tasks
void ToDoList::showRemovedTasks() const {
    if (removedTasks.empty()) {
        cout << "No removed tasks.\n";
        return;
    }
    cout << "Removed Tasks:\n";
    int i = 1;
    for (const auto& task : removedTasks) {
        cout << i << ". " << task.getDescription() << endl;
        i++;
    }
}

// Return a removed task to the main list by index
void ToDoList::returnRemovedTask(int index) {
    if (index <= 0 || index > removedTasks.size()) {
        cout << "Invalid index.\n";
        return;
    }
    auto it = removedTasks.begin();
    advance(it, index - 1);
    tasks.push_back(*it);
    removedTasks.erase(it);
}

// Return a done task to not done status
void ToDoList::returnDoneTask() {
    showDoneTasks();
    if (doneTasks.empty()) return;

    int index;
    cout << "Enter the index of the task to mark as not done: ";
    cin >> index;
    if (index <= 0 || index > doneTasks.size()) {
        cout << "Invalid index.\n";
        return;
    }
    auto it = doneTasks.begin();
    advance(it, index - 1);
    it->markNotDone();
    tasks.push_back(*it);
    doneTasks.erase(it);
}

// Clear all tasks, done tasks, and removed tasks
void ToDoList::clearAllTasks() {
    tasks.clear();
    doneTasks.clear();
    removedTasks.clear();
}

// Show all tasks that are not done
void ToDoList::showNotDoneTasks() const {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "Not Done Tasks:\n";
    int i = 1;
    for (const auto& task : tasks) {
        if (!task.isDone()) {
            cout << i << ". " << task.getDescription() << " (Not Done)" << endl;
        }
        i++;
    }
}

// Count the number of tasks in the main list
int ToDoList::countTasks() const {
    return tasks.size();
}
