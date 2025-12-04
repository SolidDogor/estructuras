#include "list_common.hpp"
#include <iostream>
#include <vector>

ListNode* swapPairs(ListNode *);

int main() {
    std::vector<int> a = {1,2,3,4};
    std::vector<int> b = {1,2,3};
    std::vector<int> c = {};
    //Creando las listas
    ListNode *l1 = createList(a);
    ListNode *l2 = createList(b);
    ListNode *l3 = createList(c);
    //Imprimiendo las listas para verificar si están correctas
    printList(l1);
    printList(l2);
    printList(l3);
    //Intercambiar cada par de la lista
    l1 = swapPairs(l1);
    l2 = swapPairs(l2);
    l3 = swapPairs(l3);
    //Imprimiendo las listas para verificar si están correctas
    printList(l1);
    printList(l2);
    printList(l3);

    return 0;
}

ListNode* swapPairs(ListNode* head) {
    //Si no hay lista, no hay nada que intercambiar
    if(!head) return nullptr;
    //Declarando una lista de ayuda
    ListNode dummy(0);
    ListNode *tail = &dummy;    //Puntero que apunta a la direc de memoria del dummy
    //Punteros para la logica de intercambio
    ListNode *prev = head;
    ListNode *curr = nullptr;
    ListNode *temp_next = nullptr;
    //Mientras tengamos un nodo anterior
    while(prev) {
        //Asignar un nodo actual como el siguiente del anterior
        curr = prev->next;
        //En caso si exista un nodo actual
        if(curr) {
            //Asignar un nodo siguiente temporal
            temp_next = curr->next;
            //Asignar el siguiente valor de la lista a retornar
            tail->next = curr;
            //Mover la lista
            tail = tail->next;
        }
        //Asignar el siguiente valor de la lista a retornar
        tail->next = prev;
        //Mover la lista
        tail = tail->next;
        //Si es que se declaro un nodo siguiente temporal
        if(temp_next) {
            //Mover el anterior al siguiente temporal
            prev = temp_next;
            //Asignarle nulo al siguiente temporal
            temp_next = nullptr;
        } else {
            //Cerrar la lista para evitar ciclos circulares
            prev = nullptr;
            tail->next = nullptr;
        }
    }
    //Retornar el siguiente valor del dummy (primer valor util)
    return dummy.next;
}