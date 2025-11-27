#ifndef LIST_COMMON_H
#define LIST_COMMON_H

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *n) : val(x), next(n) {}
};

//Creador de lista desde un vector
inline ListNode* createList(const std::vector<int>& vals) {
    if(vals.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for(size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

inline void printList(ListNode* head) {
    if(!head) {
        std::cout << "Empty list!\n";
        return;
    }
    while(head) {
        std::cout << head->val;
        (head->next) ? std::cout << " -> " : std::cout << " -> nullptr\n";
        head = head->next;
    }
}

#endif