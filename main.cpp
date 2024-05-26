#include <iostream>
#include "todo_list.h"

using namespace std;

int main() {
    ToDoList todoList;

    cout << "Data Structures Project 2024\n      TO-DO LIST         \n" << endl;

    int choice;
    do {
        // Display menu options
        cout << "\n Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Mark Task as Done\n";
        cout << "5. Edit Task Description\n";
        cout << "6. Show Done Tasks\n";
        cout << "7. Show Removed Tasks\n";
        cout << "8. Return Removed Task\n";
        cout << "9. Return Done Task\n";
        cout << "10. Clear All Tasks\n";
        cout << "11. Show Not Done Tasks\n";
        cout << "12. Count Tasks\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add a new task
                string description;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                todoList.addTask(description);
                break;
            }
            case 2: {
                // Remove a task by index
                todoList.displayTasks();
                int index;
                cout << "Enter index of task to remove: ";
                cin >> index;
                todoList.removeTask(index);
                break;
            }
            case 3:
                // Display all tasks
                todoList.displayTasks();
                break;
            case 4:
                // Mark a task as done
                todoList.markTaskDone();
                break;
            case 5: {
                // Edit a task description by index
                todoList.displayTasks();
                int index;
                cout << "Enter index of task to edit: ";
                cin >> index;
                todoList.editTaskDescription(index);
                break;
            }
            case 6:
                // Show all done tasks
                todoList.showDoneTasks();
                break;
            case 7:
                // Show all removed tasks
                todoList.showRemovedTasks();
                break;
            case 8: {
                // Return a removed task by index
                todoList.showRemovedTasks();
                int index;
                cout << "Enter index of task to return: ";
                cin >> index;
                todoList.returnRemovedTask(index);
                break;
            }
            case 9:
                // Return a done task to not done
                todoList.returnDoneTask();
                break;
            case 10:
                // Clear all tasks
                todoList.clearAllTasks();
                break;
            case 11:
                // Show all not done tasks
                todoList.showNotDoneTasks();
                break;
            case 12:
                // Count the number of tasks
                cout << "Number of tasks: " << todoList.countTasks() << endl;
                break;
            case 0:
                // Exit the program
                cout << "Exiting...\n";
                break;
            default:
                // Handle invalid menu choice
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
