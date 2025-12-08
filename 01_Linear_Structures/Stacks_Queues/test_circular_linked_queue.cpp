#include "circular_linked_queue.hpp"
#include <iostream>

int main() {
    CircularQueue<int> cq;
    cq.enQueue(1);
    cq.enQueue(2);
    cq.enQueue(3);
    cq.enQueue(4);
    cq.enQueue(5);
    cq.enQueue(6);
    cq.enQueue(7);

    cq.print();

    cq.deQueue();
    cq.deQueue();
    cq.deQueue();

    cq.print();

    return 0;
}