#include "deque.cpp"
#include <iostream>
#include <cassert>

void testDeque() {
    Deque d;

    // Test push_back
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    assert(d.length() == 3);
    assert(d.top() == 10);
    assert(d.back() == 30);

    // Test push_front
    d.push_front(5);
    assert(d.length() == 4);
    assert(d.top() == 5);

    // Test pop_front
    assert(d.pop_front() == 5);
    assert(d.length() == 3);
    assert(d.top() == 10);

    // Test pop_back
    assert(d.pop_back() == 30);
    assert(d.length() == 2);
    assert(d.back() == 20);

    // Test resize (expand)
    for (int i = 0; i < 20; i++) {
        d.push_back(i);
    }
    assert(d.capacity() > 10);

    // Test resize (shrink)
    for (int i = 0; i < 15; i++) {
        d.pop_front();
    }
    assert(d.capacity() > 10);

    // Test copy constructor
    Deque d2 = d;
    assert(d2.length() == d.length());
    assert(d2.top() == d.top());

    // Test assignment operator
    Deque d3;
    d3 = d;
    assert(d3.length() == d.length());
    assert(d3.back() == d.back());

    std::cout << "All tests passed!\n";
}

int main() {
    testDeque();
    return 0;
}
