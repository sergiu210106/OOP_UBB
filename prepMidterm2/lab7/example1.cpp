#include <iostream>
#include <exception>

using namespace std;

class Animal {
    public:
        void speak() {
            cout << "???" << endl;
        }
};

class Cat : public Animal {
    public:
        void speak() {
            cout << "Meow!" << endl;
        }
};

class Dog : public Animal {
    public:
        void speak() {
            cout << "Woof!" << endl;
        }
};

int main() {
    Dog d{};
    Cat *c {new Cat{}};
    Animal * aCat{c};
    Animal aDog{d};

    aCat->speak();
    aDog.speak();

    delete c;
    return 0;
}

/* 
OUTPUT
???
???
*/