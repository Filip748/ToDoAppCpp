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
    /**
     * @brief Constructor
     * @param text string, task content
     * @param priorityLevel integer
     */
    Task(const std::string& text, int priorityLevel);

    /**
     * @brief Destructor
     */
    ~Task();

    /**
     * @brief Getters acces to the data
     */
    int getId() const { return m_id; }
    bool getIsCompleted() const { return m_isCompleted; }
    int getPriority() const { return m_priorityLevel; }

    /**
     * @brief mark task as completed or uncompleted
     */
    void completeTask(bool isCompleted);

    /**
     * @brief overloaded operator << prints task data
     * @param task class Task
     */
    friend std::ostream& operator<<(std::ostream& os, const Task& task);
};