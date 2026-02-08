#pragma once

#include "task.hpp"
#include <vector>

class List {
private:
    std::vector<Task> m_tasks;
public:
    
    /**
     * @brief Constructor
     */
    List() {};
    
    /**
     * @brief Destructor
     */
    ~List() {};

    /**
     * @brief comparator for sort function by priority
     * @param a class Task
     * @param b class Task
     */
    Task compPriority(Task a, Task b);

    /**
     * @brief Sort vector by priority
     */
    void sortByPriority();

    /**
     * @brief adds tasks to the vector, sorts vector
     * @param text string& task content
     * @param priorityLevel int, if not specified = 0
     */
    void addTask(const std::string& text, int priorityLevel = 0);

    /**
     * @brief finds task by id
     * @param id integer
     * @return index of the matching id, otherwise -1
     */
    int findById(int id);

    /**
     * @brief deletes task with wanted id
     * @param id integer
     */
    void deleteTask(int id);

    /**
     * @brief mark as completed
     * @param id integer
     */
    void markAsCompleted(int id);

    /**
     * @brief mark as uncompleted
     * @param id integer
     */
    void markAsUncompleted(int id);

    /**
     * @brief deletes all completed tasks
     */
    void deleteAllCompleted();
    
    /**
     * @brief overloaded operator <<, prints list with tasks data
     */
    friend std::ostream& operator<<(std::ostream& os, const List& list);
};