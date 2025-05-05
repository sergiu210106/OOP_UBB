#pragma once
#include <vector>
#include <string>
class StringUtils {
public:
    //this splits the string str based on provided delimiter
    //returns vector of strings (the substrings obtained by separating based
    //on the delimiter)
    static std::vector<std::string> split(const std::string& str, char delimiter);

    
};