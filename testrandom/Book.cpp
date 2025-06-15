#include "Book.h"

Book::Book() {
    title = "Unknown";
    pages = 50 + rand() % 1950;
    string genres[] = {"Fiction", "NonFiction", "Science", "Biography"};
    genre = genres[rand()%4];
}

Book::Book(string t, int p, string g) {
    title = t;
    pages = p;
    genre = g;
}

bool Book::operator<(const Book & other) {
    return pages < other.pages;
}

ostream& operator<<(ostream& os, const Book & b) {
    os << b.title << " " << b.pages << " " << b.genre << '\n';
    return os;
}

istream& operator>>(istream& is, Book & b) {
    is >> b.title >> b.pages >> b.genre;
    return is;
}

string Book::classifyDificulty(int pages) {
    if (pages <= 200) {
        return "easy";
    } else if (pages <= 400) {
        return "moderate";
    } else if (pages <= 700) {
        return "challenging";
    } else {
        return "epic";
    }
}