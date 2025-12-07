#include "min_stack.hpp"
#include <iostream>

int main() {
    minStack<int> s;
    s.push(10);
    s.push(5);
    s.push(8);
    s.push(2);

    std::cout << s.getMin() << "\n";
    s.pop();
    std::cout << s.getMin() << "\n";

    return 0;
}