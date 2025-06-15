#include "ReadingLog.h"

using namespace std;

int main () {
    Book b1, b2, b3, b4, b5;

    Book * b6 = new Book();
    Book * b7 = new Book();

    cout << b1 << b2 << b3 << b4 << b5 << *b6 << *b7;

    ReadingLog rl;
    rl.add(b1,0);
    rl.add(b2,1);
    rl.add(b3,2);
    rl.add(b4,3);
    rl.add(b5,4);
    rl.add(*b6,5);
    rl.add(*b7,6);

    cout << rl.fictionCounter << '\n';

    int maxPages = 0;
    for (int i = 0; i < 10; i ++) {
        if (rl.books[i].pages > maxPages)
            maxPages = rl.books[i].pages;
    }

    cout << b1.classifyDificulty(maxPages) << endl;

    return 0;
}