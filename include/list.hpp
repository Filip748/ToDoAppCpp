#pragma once

#include "task.hpp"
#include <vector>

class List {
private:
    std::vector<Task> m_tasks;
public:
    List() {};
    ~List() {};

    void addTask(const std::string& text, int priorityLevel);

    int findById(int id);

    void deleteTask(int id);

    void markAsCompleted(int id);

    void markAsUncompleted(int id);

    void deleteAllCompleted();
    
    friend std::ostream& operator<<(std::ostream& os, const List& list);
};