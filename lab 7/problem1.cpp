#include <iostream>
#include <string>
using namespace std;
class Vehicle {
    protected:
        string m_registrationNumber;
    
    public:
        Vehicle() {m_registrationNumber = "";}
        Vehicle(string regNumber) : m_registrationNumber{regNumber} {}
        virtual void display() const {
            cout << "Vehicle with registration number " << m_registrationNumber << '\n';
        }    
};

class Car : public Vehicle {
    private:
        string m_bodyStyle;
    public:
        Car(string regNumber, string bodyStyle) : Vehicle{regNumber} {
            m_bodyStyle = bodyStyle;
        }
        string getBodyStyle() const {
            return m_bodyStyle;
        }

        void setBodyStyle(string newBodyStyle) {
            m_bodyStyle = newBodyStyle;
        }

        void display() const override {
            cout << "Car:\n\t";
            Vehicle::display();
            cout << "\tBody Style: " << m_bodyStyle << '\n';
        }
};

class Truck : public Vehicle{
    private:
        double m_payloadCapacity;
    public:
        Truck(string regNumber, double payload) : Vehicle{regNumber} {
            m_payloadCapacity = payload;
        }

        double getPayload() const {
            return m_payloadCapacity;
        }

        void setPayload(double newPayload) {
            m_payloadCapacity = newPayload;
        }

        void display() const override {
            cout << "Truck:\n\t";
            Vehicle::display();
            cout << "\tPayload: " << m_payloadCapacity << '\n';
        }
};


class Garage {
    private:
        Vehicle *elems[105];
        int m_numberOfVehicles;
    public:
        int getNumberOfVehicles() const {
            return m_numberOfVehicles;
        }

        void addVehicle(Vehicle *v) {
            m_numberOfVehicles++;
            elems[m_numberOfVehicles - 1] = v;
        }

        Garage() {
            m_numberOfVehicles = 0;
        };

        void displayAll() const {
            for (int i = 0; i < m_numberOfVehicles; i ++){
                elems[i]->display();
                cout << "-------------------------------------------------------------------------------------------------\n";
            }
        }
};
int main() {
    // Create objects
    Car car1("ABC123", "Sedan");
    Car car2("XYZ789", "Hatchback");
    Truck truck1("TRK001", 4500.5);
    Truck truck2("TRK002", 7500);

    // Create Garage
    Garage myGarage;

    // Add vehicles (as pointers)
    myGarage.addVehicle(&car1);
    myGarage.addVehicle(&car2);
    myGarage.addVehicle(&truck1);
    myGarage.addVehicle(&truck2);

    // Display them
    cout << "Number of vehicles in the garage: " << myGarage.getNumberOfVehicles() << "\n\n";
    myGarage.displayAll();

    return 0;
}
