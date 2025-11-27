#include <iostream>
#include <vector>
#include "list_common.hpp"

//Prototipado de funciones
ListNode* mergeSorted(ListNode *, ListNode *);

int main() {
    //Declarando vectores para inicializar listas
    std::vector<int> a1 = {1,2,4};
    std::vector<int> a2 = {1,3,4};
    //Creando listas
    ListNode *l1 = createList(a1);
    ListNode *l2 = createList(a2);
    //Imprimir listas para verificar posibles fallos
    printList(l1);
    printList(l2);
    //Unir ambas listas
    ListNode *l = mergeSorted(l1,l2);
    //Imprimir lista para verificar posibles fallos
    printList(l);

    return 0;
}

//Definición de funciones
ListNode* mergeSorted(ListNode *l1, ListNode *l2) {
    //Se crea una lista con un valor temporal
    ListNode temp(0);
    //Se crea un puntero que comienza apuntado al inicio de la lista que será devuelta
    ListNode* tail = &temp;
    //Bucle para recorrer la lista
    while(l1 && l2) {
        //Si el valor de lista 1 es menor que el de lista 2...
        if(l1->val < l2-> val) {
            //...asignar el valor de l1 a la lista que será devuelta
            tail->next = l1;
            l1 = l1->next;
        } else {
            //Sino asignar el valor de l2 a la lista que será devuelta
            tail->next = l2;
            l2 = l2->next;
        }
        //Mover la lista
        tail = tail->next;
    }
    //Completar la lista con la lista que aun contenga datos
    (!l1) ? tail->next = l2 : tail->next = l1;
    //Retornar el siguiente valor a la cabeza (el primer valor es temporal)
    return temp.next;
}