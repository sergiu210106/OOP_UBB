#ifndef TASK_REPOSITORY_H
#define TASK_REPOSITORY_H

#include "duration.h"
#include <stdexcept>

class Task {
public:
    int id;
    Duration d;

    Task();
    Task(int id, Duration d);
};

class TaskRepository {
private:
    Task* elems;
    unsigned int capacity, length;

public:
    TaskRepository(unsigned int capacity);
    void push(Task t);
    void print(char delimiter);
    Duration totalDuration();
    void deleteAllTasks();
    int count_tasks_between(float min_duration, float max_duration);
};

#endif
