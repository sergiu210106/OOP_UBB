#include <iostream>
#include <ostream>
#include <istream>
#include <stdexcept>

using namespace std;

class Stack{ 
    private:
        unsigned int numberOfElements;
        unsigned int capacity;
        int *data;
    public:
        Stack(unsigned int capacity) : numberOfElements{0}, capacity{capacity}, data{new int[capacity]} {}
        
        unsigned int size() const {
            return numberOfElements;
        }

        unsigned int getCapacity() const {
            return capacity;
        }

        void push(int value) {
            if (numberOfElements == capacity) {
                unsigned int newCapacity = capacity * 2;

                int * temp = new int[newCapacity];
                for (int i = 0; i < numberOfElements; i ++) {
                    temp[i] = data[i];
                }

                delete[] data;
                data = temp;
                capacity = newCapacity;
            }

            numberOfElements++;
            data[numberOfElements - 1] = value;
        }

        int pop() {
            if (numberOfElements == 0) {
                throw invalid_argument("Stack is empty!");
            }
            
            int lastElement = data[numberOfElements - 1];
            numberOfElements --;

            return lastElement;
        }

        ~Stack() {
            delete[] data;
        }

        Stack& operator=(const Stack& other) {
            if (this != &other) {
                delete[] data;

                capacity = other.capacity;
                numberOfElements = other.numberOfElements;
                data = new int[capacity];

                for (int i = 0; i < numberOfElements; i ++) {
                    data[i] = other.data[i];
                }
            }

            return *this;
        }
        
        Stack(const Stack &other) {
            numberOfElements = other.numberOfElements;
            capacity = other.capacity;
            data = new int[capacity];

            for (int i = 0; i < numberOfElements; i ++) {
                data[i] = other.data[i];
            }
        }

        friend ostream& operator<<(ostream& os, const Stack& s) {
            os << "Capacity: " << s.capacity << "\nNumber of elements: " << s.numberOfElements << '\n';

            for (int i = 0; i < s.numberOfElements; i ++)
                os << s.data[i] << " ";
            os << '\n';
            return os;
        }

        friend istream& operator>>(istream& is, Stack& s) {
            unsigned int newCapacity; is >> newCapacity;

            s = Stack(newCapacity);

            unsigned int newSize; is >> newSize;
            for (int i = 0; i < newSize; i ++){
                int value; is >> value;
                s.push(value);
            }

            return is;
        }
};