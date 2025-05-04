#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile{"my_file.txt", std::ios::app};
    
    if (!outFile) {
        std::cerr << "Failed to open file for writing!\n";
        return 1;
    }
    
    outFile << '1';
    outFile.close(); 

    std::ifstream inFile{"my_file.txt"};
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file for reading!\n";
        return 1;
    }

    std::string firstLine;
    std::getline(inFile, firstLine);

    std::cout << firstLine;

    return 0;
}
