#include "list_common.hpp"
#include <iostream>
#include <vector>

ListNode *partList(ListNode *, int);

int main() {
    std::vector<int> a = {1,4,3,2,5,2};
    ListNode *l = createList(a);
    int x = 3;
    //Imprimir la lista para verificar que esté correcta
    printList(l);
    //Partir la lista
    l = partList(l,x);
    //Imprimir la lista post-partición
    printList(l);
    return 0;
}

ListNode *partList(ListNode *head, int x) {
    if(!head) return nullptr;
    //Se declara dos nodos para separar la lista primero en la parte pequeña...
    ListNode smallDummy(0);
    ListNode *smallTail = &smallDummy;
    //...luego en la parte mas grande que x
    ListNode largeDummy(0);
    ListNode *largeTail = &largeDummy;
    //Bucle para agregar valores a cada lista
    while(head) {
        if(head->val < x) {
            smallTail->next = head;
            smallTail = smallTail->next;
        } else {
            largeTail->next = head;
            largeTail = largeTail->next;
        }
        head = head->next;
    }
    //El último nodo grande todavía apunta a algo (quizás a un nodo pequeño)
    //Hay que terminar la lista grande explícitamente
    largeTail->next = nullptr; 
    //Unir la cola de pequeños con la cabeza de grandes
    smallTail->next = largeDummy.next;
    //Retornar el inicio de los pequeños
    return smallDummy.next;
}