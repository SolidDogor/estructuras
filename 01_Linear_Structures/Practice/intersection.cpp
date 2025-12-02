#include "list_common.hpp"
#include <iostream>
#include <vector>

ListNode *getIntersectionNode(ListNode *, ListNode *);

int main() {
    std::vector<int> number1List = {1,2,3,4,5,6,7,8};
    std::vector<int> number2List = {7,8,9,10};
    std::vector<int> number3List = {11,12,13,14,15};

    ListNode *a = createList(number1List);
    ListNode *b = createList(number2List);
    ListNode *c = createList(number3List);
    ListNode *d = createList(number1List);
    ListNode *e = createList(number2List);
    
    a->next = c;
    b->next = c;

    ListNode *firstInter = getIntersectionNode(a,b);
    ListNode *secondInter = getIntersectionNode(d,e);

    std::cout << "Interseccion de listas: ";
    if(firstInter) std::cout << firstInter->val << "\n";
    else std::cout << "No hay interseccion." << "\n";
    std::cout << "Interseccion de listas: ";
    if(secondInter) std::cout << secondInter->val << "\n";
    else std::cout << "No hay interseccion." << "\n";

    return 0;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB) {
        std::cout << "Una de listas esta vacia.\n";
        return nullptr;
    }

    ListNode *auxA = headA;
    ListNode *auxB = headB;

    while(auxA != auxB) {
        (!auxA) ? auxA = headB : auxA = auxA->next;
        (!auxB) ? auxB = headA : auxB = auxB->next;
    }

    return auxA;
}