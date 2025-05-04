#include <iostream>
#include <fstream>

int main() {
    // open my_file.txt for reading
    std::ifstream inFile{"my_file.txt"};

    // check that we could open the file
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for reading\n";
        return -1;
    }

    // read the first line
    std::string firstLine;
    std::getline(inFile, firstLine);

    std::cout << "The first line of the file is: " << firstLine << std::endl;

    unsigned int nr = 0;
    while (inFile) {
        // then read the numbers using the stream extraction operator
        inFile >> nr;

        // display it
        std::cout << nr << std::endl;
    }

    return 0;
    // when inFile goes out of scope, the destructor automatically closes it
}