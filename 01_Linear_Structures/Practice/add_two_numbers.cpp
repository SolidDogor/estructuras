#include "list_common.hpp"
#include <iostream>
#include <vector>

ListNode *sumLists(ListNode *, ListNode *);

int main() {
    std::vector<int> a = {2,4,3}; // 342
    std::vector<int> b = {5,6,4}; // 465
    std::vector<int> c = {9,9,9}; // 999
    std::vector<int> d = {1};     // 1

    ListNode *l1 = createList(a);
    ListNode *l2 = createList(b);
    ListNode *l3 = createList(c);
    ListNode *l4 = createList(d);

    std::cout << "Suma 1 (342 + 465): ";
    ListNode *sum1 = sumLists(l1,l2);
    printList(sum1); //Esperado: 7 -> 0 -> 8

    std::cout << "Suma 2 (999 + 1):   ";
    ListNode *sum2 = sumLists(l3,l4);
    printList(sum2); //Esperado: 0 -> 0 -> 0 -> 1

    return 0;
}

ListNode *sumLists(ListNode *l1, ListNode *l2) {
    //Se usa un Dummy Node en el Stack para anclar el inicio
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    int carry = 0; //El acarreo es solo un entero, no un nodo

    //Bucle Unificado: Mientras haya algo que procesar en l1, l2 o carry...
    while(l1 != nullptr || l2 != nullptr || carry != 0) {
        //...extraemos valores (si el nodo es null, su valor es 0)
        int x = (l1 != nullptr) ? l1->val : 0;
        int y = (l2 != nullptr) ? l2->val : 0;
        
        int sum = x + y + carry;
        
        //Matemáticas de acarreo
        carry = sum / 10;      // Ejemplo: 15 / 10 = 1
        int digit = sum % 10;  // Ejemplo: 15 % 10 = 5
        
        //Crear el nuevo nodo y avanzar tail
        tail->next = new ListNode(digit);
        tail = tail->next;
        
        //Avanzar punteros de las listas si existen
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    
    //Retornar el siguiente del dummy (la cabeza real)
    return dummy.next;
}