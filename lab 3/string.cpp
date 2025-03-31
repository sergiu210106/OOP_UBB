#include <iostream>
#include <string>

int main(){
	// creating an empty string
	std::string emptyString;

	// initializing a string with a literal
	std::string greeting = "Hello World";

	// concatenating strings
	std::string firstName = "John";
	std::string lastName = "Doe";
	std::string fullName = firstName + " " + lastName;

	// displaying created strings
	std::cout << "Empty string: " << emptyString << std::endl;
	std::cout << "Greeting: " << greeting << std::endl;
	std::cout << "Full Name: " << fullName << std::endl;
	return 0;
}
