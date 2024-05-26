#ifndef TASK_H
#define TASK_H

#include <string>

// Class representing a single task
class Task {
private:
    std::string description; // Task description
    bool done;               // Task completion status
public:
    // Constructor to initialize a task with a description
    Task(const std::string& desc) : description(desc), done(false) {}

    // Getter for the task description
    std::string getDescription() const {
        return description;
    }

    // Setter for the task description
    void setDescription(const std::string& desc) {
        description = desc;
    }

    // Check if the task is done
    bool isDone() const {
        return done;
    }

    // Mark the task as done
    void markDone() {
        done = true;
    }

    // Mark the task as not done
    void markNotDone() {
        done = false;
    }
};

#endif // TASK_H
