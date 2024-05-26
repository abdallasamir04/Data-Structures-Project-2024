#include <iostream>
#include "todo_list.h"

using namespace std;

int main() {
    ToDoList todoList;

    cout <<"Data Structures Project 2024\n      TO-DO LIST         \n" << endl;

    int choice;
    do {
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
        cout << "13. Check if Task is Done\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                todoList.addTask(description);
                break;
            }
            case 2: {
                todoList.displayTasks();
                int index;
                cout << "Enter index of task to remove: ";
                cin >> index;
                todoList.removeTask(index);
                break;
            }
            case 3:
                todoList.displayTasks();
                break;
            case 4:
                todoList.markTaskDone();
                break;
            case 5: {
                todoList.displayTasks();
                int index;
                cout << "Enter index of task to edit: ";
                cin >> index;
                todoList.editTaskDescription(index);
                break;
            }
            case 6:
                todoList.showDoneTasks();
                break;
            case 7:
                todoList.showRemovedTasks();
                break;
            case 8: {
                todoList.showRemovedTasks();
                int index;
                cout << "Enter index of task to return: ";
                cin >> index;
                todoList.returnRemovedTask(index);
                break;
            }
            case 9:
                todoList.returnDoneTask();
                break;
            case 10:
                todoList.clearAllTasks();
                break;
            case 11:
                todoList.showNotDoneTasks();
                break;
            case 12: {
                int count = todoList.countTasks();
                cout << "Total number of tasks: " << count << endl;
                break;
            }
            case 13: {
                todoList.displayTasks();
                int index;
                cout << "Enter index of task to check: ";
                cin >> index;
                todoList.checkTaskDone(index);
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
