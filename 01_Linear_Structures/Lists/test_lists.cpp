#include <iostream>
#include "DoublyLinkedList.hpp"

int main() {
    std::cout << "\tPrueba: Creacion y asignacion de valores en una lista enlazada\n";
    //Instancia de la doble lista
    DoublyLinkedList<int> Lista;
    //Agregando valores al final
    Lista.push_back(4);
    Lista.push_back(3);
    Lista.push_back(9);
    Lista.push_back(9);
    //Imprimiendo lista
    Lista.print_back();
    Lista.print_front();
    //Agregando valores al inicio
    Lista.push_front(10);
    Lista.push_front(11);
    Lista.push_front(1);
    Lista.push_front(0);
    //Imprimiendo lista
    Lista.print_back();
    Lista.print_front();
    //Limpiando la lista
    Lista.clear();
    //Imprimiendo lista
    Lista.print_back();
    Lista.print_front();
    //Reviviendo la lista
    Lista.push_back(4);
    Lista.push_back(3);
    Lista.push_front(2);
    Lista.push_front(1);
    //Imprimiendo lista
    Lista.print_back();
    Lista.print_front();
    //Limpiando la lista
    Lista.clear();

    return 0;
}