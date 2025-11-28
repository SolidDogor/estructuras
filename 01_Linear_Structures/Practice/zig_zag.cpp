#include "list_common.hpp"
#include <iostream>
#include <vector>

//Prototipo
ListNode *zigzagList(ListNode *);

int main() {
    std::vector<int> a = {1,2,3,4,5};
    std::vector<int> b = {1,2,3,4};

    ListNode* l1 = createList(a);
    ListNode* l2 = createList(b);

    ListNode *list1 = zigzagList(l1);
    ListNode *list2 = zigzagList(l2);

    printList(list1);
    printList(list2);

    return 0;
}

//Definición
ListNode *zigzagList(ListNode *head) {
    if (!head || !head->next) return head;

    //Encontrar la mitad (y detenerse ANTES del inicio de la 2da mitad)
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next) { // Ojo al cambio sutil aquí para que slow quede uno antes
        slow = slow->next;
        fast = fast->next->next;
    }

    //Cortar y Reverse
    ListNode *secondHalf = slow->next; //El inicio de la 2da mitad
    slow->next = nullptr;              //Fin de la 1ra mitad
    
    //Invertir secondHalf
    ListNode *prev = nullptr;
    ListNode *curr = secondHalf;
    ListNode *next_temp = nullptr;
    while (curr) {
        next_temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_temp;
    }
    //Ahora 'prev' es la cabeza de la 2da mitad invertida
    //'head' es la cabeza de la 1ra mitad

    //Merge (Zig-Zag) In-Place
    ListNode *p1 = head; //Puntero lista 1
    ListNode *p2 = prev; //Puntero lista 2 (invertida)
    
    while (p2) { //La segunda mitad siempre es igual o más corta
        //Guardamos los siguientes pasos para no perdernos
        ListNode *nxt1 = p1->next;
        ListNode *nxt2 = p2->next;
        
        //Hacemos el cruce
        p1->next = p2;
        p2->next = nxt1;
        
        //Avanzamos
        p1 = nxt1;
        p2 = nxt2;
    }

    return head;
}