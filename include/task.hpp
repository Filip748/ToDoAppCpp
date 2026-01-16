#pragma once

#include <string>

class Task {
private:
    inline static int s_nextId = 1;

    int m_id;
    std::string m_text;
    int m_priorityLevel;
    bool m_isCompleted;
public:
    Task(const std::string& text, int priorityLevel);
    ~Task();

    int getId() { return m_id; }
    int getIsCompleted() { return m_isCompleted; }

    void completeTask(bool isCompleted);

    friend std::ostream& operator<<(std::ostream& os, const Task& task);
};