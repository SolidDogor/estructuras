#include <iostream>
#include <vector>
#include "list_common.hpp"

//Prototipo
ListNode* createCycleList();
ListNode* createNoCycleList();
bool isInfiniteList(ListNode*);

int main() {
    ListNode* cycleList = createCycleList();
    ListNode* noCycleList = createNoCycleList();

    (isInfiniteList(cycleList)) ? 
        std::cout << "Se encontro una lista infinita!\n" :
        std::cout << "No se encontro una lista infinita!\n";

    (isInfiniteList(noCycleList)) ? 
        std::cout << "Se encontro una lista infinita!\n" :
        std::cout << "No se encontro una lista infinita!\n";


    return 0;
}

//Definiciones
ListNode* createCycleList() {
    std::vector<int> a;
    for(int i = 0; i < 10; i++) {
        a.push_back(i);
    }
    ListNode* temp = createList(a);
    ListNode* aux = temp;
    ListNode* tail = temp;

    while(tail->next) tail = tail->next;
    
    int n = 4;
    while(n) {
        aux = aux->next;
        n--;
    }

    tail->next = aux;

    return temp;
}

ListNode* createNoCycleList() {
    std::vector<int> a;
    for(int i = 0; i < 10; i++) {
        a.push_back(i);
    }
    ListNode* temp = createList(a);

    return temp;
}

bool isInfiniteList(ListNode* list) {
    ListNode* fast = list;
    ListNode* slow = list;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    return false;
}