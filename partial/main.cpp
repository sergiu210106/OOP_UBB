#pragma once
#include "duration.h"
#include "taskRepository.h"
#include <cassert>
#include <iostream>

void test_duration() {
    Duration d1(1, 'h');
    Duration d2(30, 'm');
    
    assert(d1.get_value() == 3600);
    assert(d2.get_value() == 1800);
    
    assert(d1.get('s') == 3600);
    assert(d2.get('m') == 30);
    assert(d1.get('h') == 1);
    
    Duration d4 = d1 + d2;
    assert(d4.get_value() == 5400);
    
    Duration d5 = d1 - d2;
    assert(d5.get_value() == 1800);
    
    assert(d2.comp(d1) == -1);
    assert(d1.comp(d2) == 1);
    
    std::cout << "Duration tests passed!" << std::endl;
}

void test_task() {
    Duration d1(45, 'm');
    Task t1(1, d1);
    assert(t1.id == 1);
    assert(t1.d.get_value() == 2700);
    
    std::cout << "Task tests passed!" << std::endl;
}

void test_task_repository() {
    TaskRepository repo(2);
    repo.push(Task(1, Duration(1, 'h')));
    repo.push(Task(2, Duration(30, 'm')));
    
    try {
        repo.push(Task(1, Duration(10, 'm')));
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(true);
    }
    
    assert(repo.totalDuration().get_value() == 5400);
    assert(repo.count_tasks_between(1000, 4000) == 1);
    
    repo.deleteAllTasks();
    assert(repo.count_tasks_between(0, 10000) == 0);
    
    std::cout << "TaskRepository tests passed!" << std::endl;
}

int main() {
    test_duration();
    test_task();
    test_task_repository();
    return 0;
}
