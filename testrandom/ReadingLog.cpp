#include "ReadingLog.h"

int ReadingLog::fictionCounter = 0;

ReadingLog::ReadingLog() {
    date = "June 2025";

    for (int i = 0; i < 10; i ++) {
        Book b;
        books.push_back(b);
        if (b.genre == "Fiction")
            fictionCounter++;
    }
}

ReadingLog::ReadingLog(const ReadingLog & other) {
    date = other.date;
    books = other.books;
}

ReadingLog ReadingLog::operator=(const ReadingLog & other) {
    if (this != &other) {
        date = other.date;
        books = other.books;
    }
    return *this;
}

void ReadingLog::add(Book& b, int index) {
    books[index] = b;
    if (b.genre == "Fiction")
    fictionCounter++;
}