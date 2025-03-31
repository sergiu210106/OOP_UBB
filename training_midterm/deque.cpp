#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

class Deque
{
private:
    int capacity;
    int numberOfElements;
    int *elems;

public:
    Deque(unsigned int capacity = 10) : elems {new int[capacity]}, numberOfElements {0}, capacity {capacity} {}

    ~Deque()
    {
        delete[] elems; 
    }

    void resize(int newCapacity)
    {
        int *temp = new int[newCapacity];

        for (unsigned int i = 0; i < numberOfElements; i++)
        {
            temp[i] = elems[i];
        }

        delete[] elems;
        elems = temp;
        capacity = newCapacity;
    }

    void push_front(int value)
    {
        if (numberOfElements + 1 > capacity)
        {
            resize(capacity * 2);
        }

        numberOfElements++;
        for (int i = numberOfElements - 1; i > 0; i--)
        {
            elems[i] = elems[i - 1];
        }
        elems[0] = value;
    }

    int pop_front()
    {
        if (numberOfElements == 0)
        {
            throw invalid_argument("Deque is empty");
        }

        if (numberOfElements - 1 <= capacity / 4)
        {
            resize(capacity / 2);
        }

        int temp = elems[0];

        for (int i = 0; i < numberOfElements - 1; i++)
            elems[i] = elems[i + 1];
        numberOfElements--;

        return temp;
    }

    void push_back(int value)
    {
        if (numberOfElements + 1 > capacity)
        {
            resize(capacity * 2);
        }
        elems[numberOfElements++] = value;
    }

    int pop_back()
    {
        if (numberOfElements == 0)
        {
            throw invalid_argument("Deque is empty");
        }

        int lastElement = elems[numberOfElements - 1];
        numberOfElements --;
        return lastElement;
    }

    int top() {
        if (numberOfElements == 0)
        {
            throw invalid_argument("Deque is empty");
        }

        return elems[0];
    }

    int back() {
        if (numberOfElements == 0)
        {
            throw invalid_argument("Deque is empty");
        }

        return elems[numberOfElements - 1];
    }
    friend ostream &operator<<(ostream &os, const Deque& d) {
        os << "Capacity: " << d.capacity << "\nNumber of elements: " << d.numberOfElements << "\n";

        for (int i = 0; i < d.numberOfElements; i ++) {
            os << d.elems[i] << " ";
        }
        os << "\n";
        return os;
    }
    friend istream &operator>>(istream &is, Deque &d) {
        unsigned int nrElements;
        is >> nrElements;
        d = Deque(nrElements);
        for (int i=0; i < nrElements; i ++) {
            int value;
            is >> value;
            d.push_back(value);
        }
        return is;
    }

    Deque(const Deque& other) {
        capacity = other.capacity;
        numberOfElements = other.numberOfElements;
        elems = new int[capacity];
        for (int i = 0; i < numberOfElements; i ++)
            elems[i] = other.elems[i];
    }

    Deque& operator=(const Deque& other) {
        if (this != &other) {
            delete[] elems;

            capacity = other.capacity;
            numberOfElements = other.numberOfElements;
            elems = new int[capacity];
            for (int i = 0; i < numberOfElements; i ++)
                elems[i] = other.elems[i];
        }
        return *this;
    }
};