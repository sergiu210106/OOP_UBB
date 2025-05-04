class Person;

#define MAX_BOOKS 1000

class Book {
	private:
		string title;
		string authors;
		int year;
		Person * owners[10];
	public:
		Book(string t, string a, int y);
};

class Person {
	private:
		string name;
		Book books[MAX_BOOKS];
	public:
		Person(string name);
};
