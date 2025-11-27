#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    //Definición anidada y privada (Encapsulamiento total)
    struct Node {
        T data;
        Node* prev;
        Node* next;
        //Constructor del Nodo: Vital para evitar basura en los punteros
        //Usamos "Member Initializer List" (la sintaxis : variable(valor))
        Node(T val) : data(val), prev(nullptr), next(nullptr) {}
    };
    //Atributos de la Lista
    Node* head;
    Node* tail;
    int size;

public:
    //Constructor de la Lista
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    //Destructor (RAII - Resource Acquisition Is Initialization)
    ~DoublyLinkedList() {
        clear();
    }
    //Métodos
    void push_back(T val);
    void push_front(T val);
    void print_front();
    void print_back();
    void clear();
};

template <typename T>
void DoublyLinkedList<T>::push_back(T val) {
    Node* newNode = new Node(val);
    //Si no hay ningun nodo, insertar de frente
    if(!head) {
        head = newNode;
        tail = newNode;
    } else {
        //Asignar el siguiente de la cola como el nuevo nodo
        tail->next = newNode;
        //Asignar el anterior del nuevo nodo como la cola
        newNode->prev = tail;
        //Reestablecer la posición de la cola
        tail = newNode;
    }

    size++;
}

template <typename T>
void DoublyLinkedList<T>::push_front(T val) {
    Node* newNode = new Node(val);
    //Si no hay ningun nodo, insertar de frente
    if(!head) {
        head = newNode;
        tail = newNode;
    } else {
        //Asignar el anterior de la cabeza como el nuevo nodo
        head->prev = newNode;
        //Asignar el siguiente del nuevo nodo como la cabeza
        newNode->next = head;
        //Reestablecer la posición de la cabeza
        head = newNode;
    }

    size++;
}

template <typename T>
void DoublyLinkedList<T>::print_front() {
    //Si no hay nada que borrar se retorna
    if(!head) {
        std::cout << "List empty!\n";
        return;
    }
    std::cout << "Quantity of nodes in list: " << size << "\n";
    Node* current = head;
    while(current) {
        std::cout << current->data;
        (current->next) ? std::cout << " <-> " : std::cout << ".\n";
        current = current->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::print_back() {
    //Si no hay nada que borrar se retorna
    if(!tail) {
        std::cout << "List empty!\n";
        return;
    }
    std::cout << "Quantity of nodes in list: " << size << "\n";
    Node* current = tail;
    while(current) {
        std::cout << current->data;
        (current->prev) ? std::cout << " <-> " : std::cout << ".\n";
        current = current->prev;
    }
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    //Si no hay nada que borrar se retorna
    if(!head) {
        std::cout << "List already empty!\n";
        return;
    }
    //Inicializar el nodo que ayudará a borrar
    Node* current = head;
    //Bucle de borrado
    while (current != nullptr) {
        //Guardar el siguiente nodo
        Node* nextNode = current->next;
        //Borrar el actual
        delete current;
        //Avanzar
        current = nextNode;
    }
    //Resetear punteros y tamaño tras borrar
    head = nullptr;
    tail = nullptr;
    size = 0;
    //Mensaje de éxito
    std::cout << "List cleared!\n";
}

#endif