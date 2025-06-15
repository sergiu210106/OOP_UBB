#include "Book.h"
#include <vector>   
class ReadingLog {
    public:
        string date;
        vector<Book> books;
        ReadingLog();
        ~ReadingLog() = default;
        ReadingLog(const ReadingLog& other);
        ReadingLog operator=(const ReadingLog & other);

        void add(Book &b, int index);
        static int fictionCounter;
};