#include "todo_list.h"

ToDoList::ToDoList() : head(nullptr) {}

ToDoList::~ToDoList() {
    Task* current = head;
    while (current) {
        Task* temp = current;
        current = current->next;
        delete temp;
    }
}

void ToDoList::addTask(const std::string& description) {
    Task* newTask = new Task(description);
    newTask->next = head;
    head = newTask;
}

void ToDoList::removeTask(int index) {
    Task* current = head;
    Task* prev = nullptr;
    int currentIndex = 1;

    while (current) {
        if (currentIndex == index) {
            current->removed = true;
            return;
        }
        prev = current;
        current = current->next;
        ++currentIndex;
    }
    cout << "Task with index " << index << " not found.\n";
}

void ToDoList::displayTasks() const {
    if (!head) {
        cout << "No tasks\n";
        return;
    }

    Task* current = head;
    int index = 1;
    while (current) {
        if (!current->removed) {
            cout << index << ". " << current->description;
            if (current->done) {
                cout << " (Done)";
            } else {
                cout << " (Not Done)";
            }
            cout << endl;
        }
        current = current->next;
        ++index;
    }
}

bool ToDoList::isTaskDone(int index) const {
    Task* current = head;
    int currentIndex = 1;
    while (current) {
        if (currentIndex == index) {
            return current->done;
        }
        current = current->next;
        ++currentIndex;
    }
    cout << "Task with index " << index << " not found.\n";
    return false;
}

void ToDoList::markTaskDone() {
    displayTasks();
    int index;
    cout << "Enter the index of the task to mark as done: ";
    cin >> index;

    Task* current = head;
    int currentIndex = 1;
    while (current) {
        if (currentIndex == index) {
            current->done = true;
            return;
        }
        current = current->next;
        ++currentIndex;
    }
    cout << "Task with index " << index << " not found.\n";
}

void ToDoList::editTaskDescription(int index) {
    Task* current = head;
    int currentIndex = 1;
    while (current) {
        if (currentIndex == index) {
            string newDescription;
            cout << "Enter new description for task " << index << ": ";
            cin.ignore();
            getline(cin, newDescription);
            current->description = newDescription;
            return;
        }
        current = current->next;
        ++currentIndex;
    }
    cout << "Task with index " << index << " not found.\n";
}

void ToDoList::showDoneTasks() const {
    Task* current = head;
    int index = 1;
    while (current) {
        if (current->done) {
            cout << index << ". " << current->description << " (Done)\n";
        }
        current = current->next;
        ++index;
    }
}

void ToDoList::showRemovedTasks() const {
    Task* current = head;
    int index = 1;
    while (current) {
        if (current->removed) {
            cout << index << ". " << current->description << " (Removed)\n";
        }
        current = current->next;
        ++index;
    }
}

void ToDoList::returnRemovedTask(int index) {
    Task* current = head;
    int currentIndex = 1;

    while (current) {
        if (currentIndex == index) {
            current->removed = false;
            return;
        }
        current = current->next;
        ++currentIndex;
    }
    cout << "Task with index " << index << " not found.\n";
}

void ToDoList::returnDoneTask() {
    showDoneTasks();
    int index;
    cout << "Enter the index of the task to mark as not done: ";
    cin >> index;

    Task* current = head;
    int currentIndex = 1;
    while (current) {
        if (currentIndex == index) {
            current->done = false;
            return;
        }
        current = current->next;
        ++currentIndex;
    }
    cout << "Task with index " << index << " not found.\n";
}

void ToDoList::clearAllTasks() {
    Task* current = head;
    while (current) {
        Task* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    cout << "All tasks cleared.\n";
}
