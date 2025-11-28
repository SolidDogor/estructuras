#include "list_common.hpp"
#include <iostream>
#include <vector>

//Prototipo
void remoneNthEnd(ListNode*&, int);

int main() {
    std::vector<int> a;
    int val, q, n;
    std::cout << "Cuantos numeros desea ingresar?";
    std::cin >> q;
    for (int i = 1; i <= q; i++) {
        std::cout << "Ingrese el valor #" << i << ": ";
        std::cin >> val;
        a.push_back(val);
    }
    ListNode *list = createList(a);
    printList(list);
    
    std::cout << "Ingrese la posicion a eliminar (antes del final): ";
    std::cin >> n;
    while(n > q) {
        std::cout << "Debe ingresar un numero menor a la cantidad! Intente de nuevo: ";
        std::cin >> n;
    } 

    remoneNthEnd(list,n);
    printList(list);    

    return 0;
}

void remoneNthEnd(ListNode*& list, int n) {
    n++;
    if(!list) {
        std::cout << "Lista vacia! Ingrese algun valor primero.\n";
        return;
    }

    ListNode* fast = list;
    while(n && fast) {
        fast = fast->next;
        n--;
    }
    if(!fast && n) {
        std::cout << list->val << " eliminado de lista.\n";
        list = list->next;
        return;
    } 
    ListNode* slow = list;
    while(fast) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* aux = slow->next;
    slow->next = aux->next;
    std::cout << aux->val << " eliminado de lista.\n";
    delete aux;
}
