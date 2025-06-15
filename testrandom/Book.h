#include <string>
#include <cstdlib>
#include <iostream>
#include <istream>
#include <ostream>
using namespace std;

class Book
{
public:
    string title;
    int pages;
    string genre;
    Book();
    Book(string t, int p, string g);
    bool operator<(const Book& other);
    friend ostream& operator<<(ostream& os, const Book & b);
    friend istream& operator>>(istream& is, Book & b);
    static string classifyDificulty(int pages);
};