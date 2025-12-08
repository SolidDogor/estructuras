#ifndef CIRCULAR_LINKED_QUEUE
#define CIRCULAR_LINKED_QUEUE

#include <iostream>

template <typename T>
class CircularQueue {
private:
    struct Node {
        T val;
        Node* next;
        Node(T x) : val(x), next(nullptr) {};
        Node(T x, Node* y) : val(x), next(y) {};
    };
    Node* head;
    Node* tail;
    T size;

public:
    CircularQueue() : head(nullptr), tail(nullptr), size(0) {}
    
    ~CircularQueue() {
        clear();
    }

    bool enQueue(T val) {
        if(isFull()) {
            std::cout << "Queue full! First deQueue a value!\n";
            return false;
        }

        if(!head) {
            Node* newNode = new Node(val); 
            head = newNode;
            tail = head;
            size++;
            return true;
        } else {
            Node* newNode = new Node(val); 
            tail->next = newNode;
            tail = tail->next;
            tail->next = head;
            size++;
            return true;
        }

        std::cout << "Error!\n";
        return false;
    }

    bool deQueue() {
        if(isEmpty()) {
            std::cout << "Queue empty! First enQueue a value!\n";
            return false;
        }

        if(head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return true;
        } else {
            Node* aux = head;
            head = head->next;
            delete aux;
            size--;
            return true;
        }

        return false;
    }

    Node* Front() {
        if(isEmpty()) {
            std::cout << "Queue empty! First enQueue a value!\n";
            return false;
        }

        return head;
    }

    Node* Rear() {
        if(isEmpty()) {
            std::cout << "Queue empty! First enQueue a value!\n";
            return false;
        }

        return tail;
    }

    bool isEmpty() {
        if(!head) return true;
        else return false;
    }

    bool isFull() {
        return size == 5;
    }

    void clear() {
        if(isEmpty()) {
            std::cout << "Queue empty!\n";
            return;
        }
        while(head != tail) {
            Node* aux = head;
            head = head->next;
            delete aux;
        }
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
        std::cout << "Queue empty!\n";
    }

    void print() {
        if(isEmpty()) {
            std::cout << "Queue empty!\n";
            return;
        }

        std::cout << "Queue: ";
        Node* hAux = head;
        while(hAux != tail) {
            std::cout << hAux->val << " -> ";
            hAux = hAux -> next;
        }
        std::cout << hAux -> val << ".\n";
    }

};

#endif