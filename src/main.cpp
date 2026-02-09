#include <iostream>
#include "task.hpp"
#include "list.hpp"

int main() {
    List mojaLista;

    mojaLista.addTask("Buy a milk", 1);
    mojaLista.addTask("Learn C++", 3);
    mojaLista.addTask("Make a database", 44);
    mojaLista.addTask("Learn Java", 2);
    mojaLista.addTask("Task without priority");

    std::cout << mojaLista; 

 
    mojaLista.markAsCompleted(1);

    std::cout << mojaLista;

    mojaLista.deleteTask(2);

    std::cout << mojaLista;

    mojaLista.addTask("Make a To Do App", 1000);
    mojaLista.deleteAllCompleted();
    std::cout << "\n--- delete all completed ---\n";
    std::cout << mojaLista;

    return 0;
}
