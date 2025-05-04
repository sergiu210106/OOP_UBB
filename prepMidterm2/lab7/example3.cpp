#include <iostream>

using namespace std;

class Shape {
    protected:
        // coordinates of the center of the shape
        // protected - can be accessed by the derived classes
        double m_x;
        double m_y;

    public:
        Shape (double x, double y) {
            m_x = x;
            m_y = y;
        }

        virtual ~Shape() = default;

        virtual double area() = 0;

        //this method is inherited by the derived classes
        void translate(double dx, double dy) {
            m_x += dx;
            m_y += dy;
        }

        virtual void displayInfo() {
            cout << "Centroid: (" << m_x << ", " << m_y << ")" << endl; 
        }
};