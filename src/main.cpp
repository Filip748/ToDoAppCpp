#include <iostream>
#include "task.hpp"
#include "list.hpp"

int main() {
    List myList;

    myList.addTask("Buy a milk", 1);
    myList.addTask("Learn C++", 3);
    myList.addTask("Make a database", 44);
    myList.addTask("Learn Java", 2);
    myList.addTask("Task without priority");

    std::cout << myList; 

 
    myList.markAsCompleted(1);

    std::cout << myList;

    myList.deleteTask(2);

    std::cout << myList;

    myList.addTask("Make a To Do App", 1000);
    myList.deleteAllCompleted();
    std::cout << "\n--- delete all completed ---\n";
    std::cout << myList;

    return 0;
}
