#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

class Deque {
    private: 
        unsigned int m_numberOfElements;
        unsigned int m_capacity;
        int* m_elements;
    
    public:
        Deque(unsigned int capacity = 10) : m_numberOfElements{0}, m_capacity{capacity}, m_elements{new int[capacity]}{}

        unsigned int capacity() const { return m_capacity; }
        unsigned int length() const { return m_numberOfElements; }

        ~Deque() {
            if (m_elements) {
                delete[] m_elements;
                m_elements = nullptr;
            }
        }
        void resize() {
            unsigned int newCapacity;
            if(m_numberOfElements == m_capacity)
                newCapacity = m_capacity * 2;
            else if (m_numberOfElements <= m_capacity / 4)
                newCapacity = m_capacity / 2;
            else
                return;

            int* temp = new int[newCapacity];

            for (unsigned int i = 0; i < m_numberOfElements; i ++) {
                temp[i] = m_elements[i];
            }

            delete[] m_elements;
            m_elements = temp;
            m_capacity = newCapacity;
        }

        void push_front(int value) {
            if (m_numberOfElements == m_capacity) {
                resize();
            }
            m_numberOfElements ++;
            for (unsigned int i = m_numberOfElements - 1; i > 0; i --) {
                m_elements[i] = m_elements[i-1];
            }
            m_elements[0] = value;
        }

        int pop_front() {
            if (m_numberOfElements == 0) {
                throw invalid_argument("The deque is empty!");
            }

            int firstElement = m_elements[0];
            for(unsigned int i = 0; i < m_numberOfElements - 1; i ++) {
                m_elements[i] = m_elements[i+1];
            }
            m_numberOfElements --;
            return firstElement;
        }

        void push_back(int value) {
            if (m_numberOfElements == m_capacity) {
                resize();
            }

            m_elements[m_numberOfElements ++] = value;
        }

        int pop_back() {
            if (m_numberOfElements == 0) {
                throw invalid_argument("The deque is empty!");
            }
            int lastElement = m_elements[m_numberOfElements - 1];
            m_numberOfElements --;
            return lastElement;
        }

        int top() {
            if (m_numberOfElements == 0) {
                throw invalid_argument("The deque is empty!");
            }

            return m_elements[0];
        }

        int back() {
            if (m_numberOfElements == 0) {
                throw invalid_argument("The deque is empty!");
            }
            return m_elements[m_numberOfElements - 1];
        }

        friend ostream &operator<<(ostream &os, const Deque& d) {
            os << "Capacity: " << d.m_capacity << "\nNumber of elements: " << d.m_numberOfElements << "\n";

            for (int i = 0; i < d.m_numberOfElements; i ++) {
                os << d.m_elements[i] << " ";
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
            m_capacity = other.m_capacity;
            m_numberOfElements = other.m_numberOfElements;

            for (int i = 0; i < m_numberOfElements; i ++)
                m_elements[i] = other.m_elements[i];
        }

        Deque& operator=(const Deque& other) {
            if (this != &other) {
                m_capacity = other.m_capacity;
                m_numberOfElements = other.m_numberOfElements;
                m_elements = new int[m_capacity];
                for (int i = 0; i < m_numberOfElements; i ++)
                    m_elements[i] = other.m_elements[i];
            }
            return *this;
        }

};