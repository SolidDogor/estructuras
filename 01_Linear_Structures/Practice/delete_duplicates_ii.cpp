#include "list_common.hpp"
#include <iostream>
#include <vector>

ListNode* deleteDuplicates(ListNode*);

int main() {
    std::vector<int> a = {1,2,2,3,3};
    std::vector<int> b = {1,2,3,3,4,4,4,4,5};
    std::vector<int> c = {1,1,2,3,3};
    //Creando listas
    ListNode* l1 = createList(a);
    ListNode* l2 = createList(b);
    ListNode* l3 = createList(c);
    //Imprimiendo listas para verificar si están correctas
    printList(l1);
    printList(l2);
    printList(l3);
    //Borrando duplicados
    l1 = deleteDuplicates(l1);
    l2 = deleteDuplicates(l2);
    l3 = deleteDuplicates(l3);
    //Imprimiendo listas para verificar si están correctas
    printList(l1);
    printList(l2);
    printList(l3);

    return 0;
}

ListNode* deleteDuplicates(ListNode* head) {
    //Si no hay nada, se retorna nada
    if(!head) return nullptr;
    //Declarar una lista de ayuda
    ListNode dummy(0);
    ListNode* tail = &dummy;    //Puntero que apunta a la dirección de memoria de la ayuda
    //Nodos de ayuda
    ListNode* curr = head;
    ListNode* temp_next = nullptr;
    //Mientras exista el nodo actual
    while(curr) {
        //Declarar el siguiente valor del actual
        temp_next = curr->next;
        if(temp_next) {
            //Asignar el valor que no se repite a la cola
            if(curr->val != temp_next->val || !temp_next) {
                tail->next = curr;
                tail = tail->next;
                curr = curr->next;
                temp_next = nullptr;
            } else {    //Encontrar un valor que no se repita
                while(temp_next && curr->val == temp_next->val) {
                    temp_next = temp_next->next;
                }
                curr = temp_next;
                temp_next = nullptr;
            }
        } else {    //Asignar el último valor para evitar ciclos
            tail->next = curr;
            tail = tail->next;
            curr = curr->next;
        }
    }
    tail->next = nullptr;
    //Retornar el siguiente valor del dummy (primer valor util)
    return dummy.next;
}
