#include <string>
#include <iostream>
using namespace std;

class Animal {
    protected:
        string m_commonName;
        string m_scientificName;
    
    public:
        Animal(string commonName, string scientficName) : 
        m_commonName{commonName}, m_scientificName(scientficName) {}

        void displayInfo() {
            cout << "Animal:\n";
            cout << "\tCommon Name: " << this->m_commonName << '\n';
            cout << "\tScientific Name: " << this->m_scientificName << '\n';
            cout << '\n';
        }
};

class Mammal : public Animal{
    private:
        bool m_isAquatic;
        unsigned char m_gestationPeriod;
    public:
        Mammal(string commonName, string scientificName, bool isAquatic, unsigned char gestationPeriod) :
        Animal(commonName, scientificName) {
            this->m_isAquatic = isAquatic;
            this->m_gestationPeriod = gestationPeriod;
        }

        void displayInfo() {
            cout << "Mammal:\n";
            Animal::displayInfo();
            cout << "\tType: ";
            cout << (this->m_isAquatic) ? "Aquatic" : "Ground";
            cout << '\n';
            cout << "\tGestation Period: " << this->m_gestationPeriod << '\n';
            cout << '\n';
        }
        
};

class Bird : public Animal {
    private:
        unsigned int m_wingSpan;
    public:
        Bird(string commonName, string scientificName, unsigned int wingSpan) :
        Animal{commonName, scientificName} {
            this->m_wingSpan = wingSpan;
        }

        void displayInfo() {
            cout << "Bird:\n";
            Animal::displayInfo();
            cout << "\tWing Span: " << this->m_wingSpan << '\n';
            cout << '\n';
        }
};

class Reptile : public Animal {
    private:
        bool m_isVenomous;
    public:
        Reptile(string commonName, string scientificName, bool isVenomous) : 
        Animal(commonName, scientificName) {
            this->m_isVenomous = isVenomous;
        }

        void displayInfo() {
            cout << "Reptile:\n";
            Animal::displayInfo();
            cout << (this->m_isVenomous) ? "\tVenomous" : "\tNot Venomous";
            cout << '\n';
        }
};

int main(){
    Animal a{"musculita de otet", "drosofila melanogaster"};
    a.displayInfo();
    return 0;
}