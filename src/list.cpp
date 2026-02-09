#include <iostream>
#include "list.hpp"
#include <algorithm>

void List::sortByPriority() {
    sort(m_tasks.begin(), m_tasks.end(), [](Task& a, Task& b) {
        return a.getPriority() > b.getPriority();
    });
}

void List::addTask(const std::string& text, int priorityLevel) {

    m_tasks.push_back(Task(text, priorityLevel));
    sortByPriority();
}

std::optional<size_t> List::findById(int id) {
    for(size_t i = 0; i < m_tasks.size(); i++) {
        if(m_tasks[i].getId() == id) {
            return i;
        }
    }
    return std::nullopt;
}

void List::deleteTask(int id) {
    std::optional<size_t> result = findById(id);
    if (result.has_value()) {
        size_t index = result.value();
        m_tasks.erase(m_tasks.begin() + index);
    }
}

void List::markAsCompleted(int id) {
    std::optional<size_t> result = findById(id);
    if (result.has_value()) {
        size_t i = result.value();
        m_tasks[i].completeTask(true);
    }
}

void List::markAsUncompleted(int id) {
    std::optional<size_t> result = findById(id);
    if (result.has_value()) {
        size_t i = result.value();
        m_tasks[i].completeTask(false);
    }
}

void List::deleteAllCompleted() {
    m_tasks.erase(
        std::remove_if(m_tasks.begin(), m_tasks.end(),
            [](const Task& t) { return t.getIsCompleted(); }),
        m_tasks.end());
}

std::ostream& operator<<(std::ostream& os, const List& list) {
    os << "\n=== TO DO LIST ===\n";
    
    if (list.m_tasks.empty()) {
        os << "(List is empty)\n";
    } else {
        for (const auto& task : list.m_tasks) {
            os << task << "\n";
        }
    }
    
    os << "=========================\n";
    return os;
}