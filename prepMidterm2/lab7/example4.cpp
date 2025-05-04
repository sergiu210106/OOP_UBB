#include <iostream>
using namespace std;

class Shape {
    protected:
        // coordinates to the center of the shape
        // protected - can be accessed by the derived classes

        double m_x;
        double m_y;
    
    public:
        Shape (double x, double y) {
            m_x = x;
            m_y = y;
        }

        virtual ~Shape() = default;

        virtual void displayInfo() {
            cout << "Centroid: (" << m_x << ", " << m_y << ")" << endl;
        }
};

class Circle : public Shape {
    private:
        double m_radius;
    
    public:
        Circle(double x, double y, double r) : Shape{x, y} {
            m_radius = r;
        }

        double diameter() const {
            return 2 * m_radius;
        }

        // redefine displayInfo()
        void displayInfo() override {
            cout << "Circle:" << endl;
            cout << "\t";
            Shape::displayInfo();
            cout << "\t" << "Radius: " << m_radius << endl;
            cout << endl;
        }
};

int main() {
    Circle c1{0,0,5};
    Circle c2{-10,10,100};

    Shape * s {new Shape {10, 10}};
    Shape *s1 {&c1}; // upcasting (this is implicit). s1 is a base class pointer
    Shape &s2 {c2}; // upcasting (this is implicit). s2 is a base class reference
    
    // downcasting
    // this will fail because s does not point to a Circle
    if (! dynamic_cast<Circle*> (s)) {
        cout << "failed to convert object s to a Circle" << endl;
    }

    // this will work, s1 and s2 refer to Circle(s)
    Circle * cp {dynamic_cast<Circle*>(s)};
    if (cp != nullptr) {
        cout << "succesfully converted s1 to a Circle pointer" << endl;
        cout << "Diameter of s1" << cp->diameter() << endl;
    } else {
        cout << "Failed to convert s1 to a Circle pointer" << endl;
    }

    try {
        Circle &cr{dynamic_cast<Circle&>(s2)};

        cout << "succesfully converted s2 to a Circle reference" << endl;
        cout << "diameter of s1" << cr.diameter() << endl;
    } catch (bad_cast& e) {
        cout << "failed to convert s2 to a circle reference" << e.what() << endl;
    }

    delete s;
    return 0;
}