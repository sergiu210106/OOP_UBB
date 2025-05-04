#include <iostream>
using namespace std;

class Shape {
    protected:
        // coordinates of the center of the shape
        // protected - can be accessed by the derived classes

        double m_x;
        double m_y;
    
    public:
        Shape(double x, double y) {
            this->m_x = x;
            this->m_y = y;
        }

        // this method is inherited by the derived class
        void translate(double dx, double dy) {
            this->m_x += dx;
            this->m_y += dy;
        }

        void displayInfo() {
            cout << "Centroid: (" << this->m_x << ", " << this->m_y << ")\n";
        }
};

class Circle : public Shape 
{
    private:
        double m_radius;
    
    public:
        // we call the base class constructor Shape{x, y}
        // this will initialize the inherited m_x and m_y attributes

        Circle(double x, double y, double r) : Shape{x, y} {
            this->m_radius = r;
        }

        // redefine the displayInfo method
        void displayInfo() {
            cout << "Circle:\n\t";
            Shape::displayInfo(); // call the displayInfo method from the parent class
            cout << "\tRadius: " << this->m_radius << "\n\n";
        }
};

class Rectangle : public Shape {
    private: 
        double m_width;
        double m_height;
    
    public:
        Rectangle(double x, double y, double w, double h) : Shape{x, y}{
            this->m_width = w;
            this->m_height = h;
        }

        // redifine the displayInfo method;
        void displayInfo() {
            cout << "Rectangle:\n\t";
            Shape::displayInfo(); // call the displayInfo method from the parent class
            cout << "\tSize: (" << this->m_width << ", " << this->m_height << ")\n\n";
        }
};

int main() {
    Circle c{10, 20, 4};
    Rectangle r{0,0,20,30};
    c.displayInfo();
    r.displayInfo();

    cout << "Translate circle with (20, -4)\n";
    c.translate(20,-4);
    c.displayInfo();
    return 0;
}