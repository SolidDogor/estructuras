#ifndef MIN_STACK_HPP
#define MIN_STACK_HPP

#include <iostream>

template <typename T>
class minStack {
private:
    struct Node {
        T val;
        T minVal;
        Node* next;
        Node(T v, T minV, Node* n) : val(v), minVal(minV), next(n) {}
    };

    Node* head;
    int size;

public:
    minStack() : head(nullptr), size(0) {}
    
    ~minStack() {
        clear();
    }

    void push(T val);
    void pop();
    T top();
    T getMin();
    void clear();
    void print();
};

template <typename T>
void minStack<T>::push(T val) {
    T newMin = val;
    
    //Si la pila NO está vacía, comparamos con el mínimo actual
    if (head && head->minVal < val) {
        newMin = head->minVal;
    }

    //El nuevo nodo apunta al antiguo head
    Node* newNode = new Node(val, newMin, head);
    head = newNode;
    size++;
}

template <typename T>
void minStack<T>::pop() {
    if(!head) {
        std::cout << "Stack Underflow!\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    size--;
}

template <typename T>
T minStack<T>::top() {
    if(!head) {
        std::cout << "Stack is empty!\n";
        return T(); //Retorno default
    }
    return head->val;
}

template <typename T>
T minStack<T>::getMin() {
    if(!head) {
        std::cout << "Stack is empty!\n";
        return T();
    }
    return head->minVal;
}

template <typename T>
void minStack<T>::print() {
    Node* curr = head;
    std::cout << "Stack (Top -> Bottom): ";
    while(curr) {
        std::cout << "[" << curr->val << "|min:" << curr->minVal << "] -> ";
        curr = curr->next;
    }
    std::cout << "nullptr\n";
}

template <typename T>
void minStack<T>::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

#endif