#include "task.hpp"
#include <iostream>

Task::Task(const std::string& text, int priorityLevel) 
    : m_text(text),
    m_priorityLevel(priorityLevel),
    m_isCompleted(0)
    {
        m_id = s_nextId;
        s_nextId++;
    }

Task::~Task() {}

void Task::completeTask(bool isCompleted) {
    m_isCompleted = isCompleted;
}

std::ostream& operator<<(std::ostream& os, const Task& task) {
    os << task.m_id << ". "
        << task.m_text
        << " [" << (task.m_isCompleted ? "Yes" : "No") << "]"
        << "   (Priority: " << task.m_priorityLevel << ")";
    return os;
}