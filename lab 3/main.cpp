#include "point.h"

// the friend function is defined in the main.cpp function, without using the scope resolution operator "::"

double distance(const Point& p1, const Point& p2){
	// the function has direct access to the private members of the class
	return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

int main(){
	Point p1(1.0, 2.0);
	Point p2(4.0, 6.0);
	double dist = distance(p1, p2);

	std::cout << "Distance between points: " << dist << std::endl;
	return 0;
}
