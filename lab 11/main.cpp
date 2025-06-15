#include <vector>
#include <string>
#include <iostream>
template <typename T>
class Stack {
    private:
        std::vector<T> items;

    public:
        void push (T item) {
            items.push_back(item);
        }

        T pop() {
            if (items.size() == 0) {
                throw std::exception("stack is empty!");
            }            

            T el = items.back();
            items.pop_back();
            return el;
        }

        T front() {
            if (items.size() == 0) {
                throw std::exception("stack is empty!");
            }

            return items.back();
        }

        void display() {
            cout << "Stack:\n";
            for (auto i = items.begin(); i != items.end(); i ++) {
                std::cout << items[i] << '\n';
            }
        }
};


int main () {
    Stack<int> sInt;
    Stack<std::string> sString; 
    Stack<char> sChar;

    try {
        sInt.front();
    }catch (std::exception & e) {
        std::cout << e.what() << '\n';
    }

    sInt.push(2);
    sInt.push(3);

    sInt.display();



    return 0;
}