#include <iostream>
#include <vector>
#include "list_common.hpp"

//Prototipado de funciones
ListNode* sortList(ListNode *);
ListNode* mergeSorted(ListNode *, ListNode *);

int main() {
    //Declarando vectores para inicializar listas
    std::vector<int> a = {4,2,1,3};

    //Creando lista
    ListNode *l1 = createList(a);

    //Imprimir lista para verificar posibles fallos
    printList(l1);

    //Ordenar la lista
    l1 = sortList(l1);

    //Imprimir lista para verificar posibles fallos
    printList(l1);

    return 0;
}

ListNode* sortList(ListNode *head) {
    //Si no hay nada o solo hay un valor, ya está ordenado
    if(!head || !head->next) return head;

    //Encontrar el lado derecho de la lista
    ListNode *right = head;
    ListNode *fast = head;
    while(fast && fast->next) {
        right = right->next;
        fast = fast->next->next;
    }
    //Encontrar la mitad
    ListNode *mid = head;
    while(mid->next != right) mid = mid->next;
    mid->next = nullptr;
    //Dividir inicio y derecha
    head = sortList(head);
    right = sortList(right);
    //Ordenar inicio y derecha
    head = mergeSorted(head,right);

    return head;
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