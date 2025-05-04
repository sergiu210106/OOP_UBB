#include <iostream>
#include <fstream>

int main() {
    // open the file in append mode (all the write operations will be performed at the end of the file)
    // if the file already exists, we just append new data to it
    std::ofstream outFile {"my_file.txt", std::ios::app};

    // check that we could open the file
    if (!outFile) {
        std::cerr << "Failed to open the file for writing\n";
        return -1;
    }

    // use the stream insertion operator to write data to the file 
    outFile << "Here are the first 100 natural numbers" << std::endl;

    for (int i = 0; i < 100; i ++)
        outFile << i << " ";
    
    // close the file
    outFile.close();

    return 0;
}