#ifndef TASK_H
#define TASK_H

#include <string>

// Task structure to represent individual tasks
struct Task {
    std::string description;
    bool done;
    bool removed;
    Task* next;

    // Constructor
    Task(const std::string& desc) : description(desc), done(false), removed(false), next(nullptr) {}
};

#endif
