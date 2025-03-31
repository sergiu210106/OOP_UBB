#pragma once
#include <fstream>

using std::ifstream;
using std::ofstream;

class Point {
	// the default access modifier in C++ is private
private:
	// these are the private attributes of the class
	float m_x; // x coordinate
	float m_y; // y coordinate
	
	// static member to count how many objects have been created
	// it is defined in point2.cpp
	static unsigned long long CREATED_INSTANCES_PARAM;

public:
	// these are the public members of the class
	Point(); // default constructor
	Point(float x, float y); // parametrized constructor
	
	// getters and setters
	// const - the this-> pointer is transformed to a constant pointer -- we are not allowed to change the state of the object
	
	// get
	float x() const;
	//inline methods can only be defined in the header of the class
	inline float y() const { return m_y; }

	//set
	void setX(float x);
	void setY(float y);

	// arithmetic operator overloading
	//
	// Overloaded + operator for adding 2 points. this operator is a class member
	Point operator+(const Point& other) const;
	// Overloaded - operator for subtracting 2 points. this operator is overloaded using friend functions
	// i.e. it is not a class member
	friend Point operator-(const Point& p1, const Point& p2);


	// stream operators overloading. these can only be overloaded as friend functions
	// overloaded stream insertion operator for "printing" the point
	friend std::ostream& operator<<(std::ostream& os, const Point& point);
	// overloaded stream extraction operator for reading in a point
	friend std::istream& operator>>(std::istream& is, Point& point);

	//static function to get the number of created instances using the parametrized constructor
	static unsigned long long numCreatedParametrized();
};
