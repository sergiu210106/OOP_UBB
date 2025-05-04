#define MAX_BOOKS 1000
class Book {
	public:
		Book(string t, string a, int y);
	private:
		string title;
		string author;
		int year;
};

class Person {
	public:
		Person(string name);
	private:
		string name;
		Book books[MAX_BOOKS];
};
