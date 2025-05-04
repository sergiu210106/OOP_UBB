#include <iostream>
#include <fstream>

int main() {
	// open my_file.txt for reading
	std::istream inFile{"my_file.txt"};

	// check that we could open the file
	if (!inFile.is_open()) {
		std::cerr << "Failed to open file for reading\n";
		return -1;
	}

	// read first line
	std::string firstLine;
	std::getline(inFile, firstLine);

	cout << "The first line of the file is : " << firstLine << '\n';

	unsigned int nr = 0;

	while (inFile) {
		// read using extraction operator
		inFile >> nr;
		// display it
		cout << nr << '\n';
	}
	return 0;
	// when inFile gets out of scope, the destructor closes it
}
