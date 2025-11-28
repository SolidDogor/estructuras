#include "list_common.hpp"
#include <iostream>
#include <vector>

//Prototipo
bool isPalindrome(ListNode *);

int main() {
    std::vector<int> a = {1,2,1};
    std::vector<int> b = {1,2,3};
    ListNode *pal = createList(a);
    ListNode *noPal = createList(b);

    (isPalindrome(pal)) ?
        std::cout << "Es una lista de palindromos.\n" :
        std::cout << "No es una lista de palindromos.\n";

    (isPalindrome(noPal)) ?
        std::cout << "Es una lista de palindromos.\n" :
        std::cout << "No es una lista de palindromos.\n";

    return 0;
}

//Definición
bool isPalindrome(ListNode *list) {
    if (!list || !list->next) return true; // Caso base: 0 o 1 elemento es palíndromo

    //Encontrar la mitad
    ListNode *slow = list;
    ListNode *fast = list;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    //Invertir la segunda mitad (Desde slow)
    //Usamos la técnica estándar: prev empieza en nullptr
    ListNode *prev = nullptr;
    ListNode *curr = slow; //slow está en el medio (o inicio de 2da mitad)
    ListNode *next_temp = nullptr;
    
    while (curr) {
        next_temp = curr->next; //Guardar siguiente
        curr->next = prev;      //Invertir flecha
        prev = curr;            //Avanzar prev
        curr = next_temp;       //Avanzar curr
    }
    //Al terminar, 'prev' es la nueva cabeza de la lista invertida

    //Comparar ambas mitades
    ListNode *left = list;
    ListNode *right = prev; //La mitad invertida
    
    while (right) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }

    return true;
}