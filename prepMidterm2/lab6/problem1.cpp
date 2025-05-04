/*
Implement a C++ class hierarchy for an animal classification system. The base class is the
Animal class with the following attributes protected commonName (string), scientificName
(string), and a method that displays information about the animal. Create a parameterized
constructor which initializes these attributes to the passed parameters.
Then create three subclasses: Mammal, Bird, and Reptile. Add specific attributes to each
derived class: the Mammal class should have an attribute isAquatic (bool) and gestationPeriod
(unsigned char); the Bird class should have an attribute wingSpan (unsigned int); and the
Reptile class should have an attribute isVenomous (bool). For each of the subclasses,
re-implement the method to display the information about the animal and also display the
values for the new attributes.
In the main function create an object from all the classes that you defined and call the
display method on all of them.
*/

#include <iostream>
#include <string>

using namespace std;

class Animal {
    protected:
        string m_commonName;
        string m_scientficName;

    public:
        Animal (string commonName, string scientificName) {
            m_commonName = commonName;
            m_scientficName = scientificName;
        }

        void displayInfo() {
            cout << "Animal: Common Name: " << m_commonName << ", Scientific Name: " << m_scientficName << endl;
        }
};

class Mammal : public Animal {
    private:
        bool m_isAquatic;
        unsigned char m_gestationPeriod;

    public:
        Mammal (string commonName, string scientificName, bool isAquatic, unsigned char gestationPeriod) : Animal {commonName, scientificName} {
            m_isAquatic = isAquatic;
            m_gestationPeriod = gestationPeriod;
        }

        void displayInfo() {
            cout << "Mammal:" << endl;
            cout << "\t";

            Animal::displayInfo();

            cout << "\t" << "Aquatic: " << m_isAquatic << endl;
            cout << "\t" << "Gestation Period: " << (int)m_gestationPeriod << endl;
            
            cout << endl;
        }
};

class Bird : public Animal {
    private:
        unsigned int m_wingSpan;

    public:
        Bird (string commonName, string scientificName, unsigned int wingSpan) : Animal{commonName, scientificName} {
            m_wingSpan = wingSpan;
        }

        void displayInfo() {
            cout << "Bird:" << endl;
            cout << "\t";

            Animal::displayInfo();

            cout << "\t" << "Wing Span: " << m_wingSpan << endl;
            
            cout << endl;
        }
};

class Reptile : public Animal {
    private:
        bool m_isVenomous;
    
    public:
        Reptile (string commonName, string scientificName, bool isVenomous) : Animal {commonName, scientificName} {
            m_isVenomous = isVenomous;
        }

        void displayInfo() {
            cout << "Reptile:" << endl;
            cout << "\t";
            
            Animal::displayInfo();

            cout << "\t" << "Is Venomous: " << m_isVenomous << endl;

            cout << endl;
        }
};

int main() {
    Mammal m{"c", "s", false, (unsigned char) 7};
    Bird b{"c", "s", 200};
    Reptile r{"c", "s", true};

    m.displayInfo();
    b.displayInfo();
    r.displayInfo();

    return 0;
}