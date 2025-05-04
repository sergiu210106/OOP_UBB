#include <iostream>
using namespace std;

class Shape
{
protected:
    // coordinates of the center of the shape
    // protected - they can be inherited by the derived classes
    double m_x;
    double m_y;

public:
    Shape(double x, double y)
    {
        m_x = x;
        m_y = y;
    }

    virtual ~Shape() = default;

    // this method is inherited by the derived classes
    void translate(double dx, double dy)
    {
        m_x += dx;
        m_y += dy;
    }

    virtual void displayInfo()
    {
        cout << "Centroid: (" << m_x << ", " << m_y << ")\n";
    }
};

class Circle : public Shape
{
private:
    double m_radius;

public:
    // we call the base class constructor Shape{x,y}
    // this will initialize the inherited m_x and m_y attributes

    Circle(double x, double y, double r) : Shape{x, y}
    {
        m_radius = r;
    }

    double diameter() const
    {
        return 2 * m_radius;
    }

    // redefine displayInfo() method
    void displayInfo() override
    {
        cout << "Circle:\n\t";
        Shape::displayInfo();
        cout << "Radius:" << m_radius << endl;
        cout << '\n';
    }
};
int main()
{
    Circle c1{0, 0, 5};
    Circle c2{-10, 10, 100};
    Shape *s{new Shape{10, 10}};
    Shape *s1{&c1}; // upcasting (this is implicit). s1 is a base class pointer
    Shape &s2{c2};  // upcasting (this is implicit). s2 is a base class reference
    // downcasting
    // this will fail because s does not point to a Circle
    if (!dynamic_cast<Circle *>(s))
    {
        cout << "Failed to convert object s to a Circle" << endl;
    }
    // the dynamic_casts below will work, because s1 and s2 actually refer to Circle(s)
    Circle *cp{dynamic_cast<Circle *>(s1)};
    if (cp != nullptr)
    {
        cout << "Successfully converted s1 to a Circle pointer" << endl;
        cout << "Diameter of s1 " << cp->diameter() << endl;
    }
    else
    {
        cout << "Failed to convert s1 to a Circle pointer" << endl;
    }
    try
    {
        Circle &cr{dynamic_cast<Circle &>(s2)};
        // exceptions will be covered in the next labs
        cout << "Successfully converted s2 to a Circle reference" << endl;
        cout << "Diameter of s1 " << cr.diameter() << endl;
    }
    catch (std::bad_cast &e)
    {
        cout << "Failed to convert s2 to a Circle reference" << e.what() << endl;
    }
    delete s;
    return 0;
}
