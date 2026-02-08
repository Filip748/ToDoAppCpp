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

int List::findById(int id) {
    int size = m_tasks.size();
    for(int i = 0; i < size; i++) {
        if(m_tasks[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

void List::deleteTask(int id) {
    int i = findById(id);
    if (i != -1) {
        m_tasks.erase(m_tasks.begin() + i);
    }
}

void List::markAsCompleted(int id) {
    int i = findById(id);
    if (i != -1) {
        m_tasks[i].completeTask(true);
    }
}

void List::markAsUncompleted(int id) {
    int i = findById(id);
    if (i != -1) {
        m_tasks[i].completeTask(false);
    }
}

void List::deleteAllCompleted() {
    std::vector<int> idToDelete;
    for(long unsigned int i = 0; i < m_tasks.size(); i++) {
        if(m_tasks[i].getIsCompleted() == true) {
            idToDelete.push_back(m_tasks[i].getId());
        }
    }
    for(long unsigned int i = 0; i < idToDelete.size(); i++) {
        deleteTask(idToDelete[i]);
    }
}

std::ostream& operator<<(std::ostream& os, const List& list) {
    os << "\n=== TWOJA LISTA ZADAN ===\n";
    
    if (list.m_tasks.empty()) {
        os << "(Lista jest pusta)\n";
    } else {
        for (const auto& task : list.m_tasks) {
            os << task << "\n";
        }
    }
    
    os << "=========================\n";
    return os;
}