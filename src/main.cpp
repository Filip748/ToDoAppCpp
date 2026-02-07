#include <iostream>
#include "task.hpp"
#include "list.hpp"

int main() {
    List mojaLista;

    mojaLista.addTask("Kupic mleko", 1);
    mojaLista.addTask("Nauczyc sie C++", 3);
    mojaLista.addTask("Zrobic baze danych", 44);
    mojaLista.addTask("Nauczyc sie Javy", 2);
    
    // Wypisanie całej listy jedną linijką!
    std::cout << mojaLista; 

    // Oznaczamy zadanie ID 1 jako zrobione
    mojaLista.markAsCompleted(1);

    std::cout << "\n--- Po zrobieniu zakupow ---\n";
    std::cout << mojaLista;

    // Usuwanie
    mojaLista.deleteTask(2);
    std::cout << "\n--- Po usuncie id 2 ---\n";
    std::cout << mojaLista;

    mojaLista.addTask("Filip to giga szef", 1000);
    mojaLista.deleteAllCompleted();
    std::cout << "\n--- Po zrobieniu usuncie all completed ---\n";
    std::cout << mojaLista;

    return 0;
}



// dodac interaktywnego maina
// gdy podamy taska bez priority to zeby priority = 1

/*
    GUI:
    QT / QML
    bedziemy miec profesjonalna aplikacje fullstackowa
*/