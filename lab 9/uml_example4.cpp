class Book {
	private:
		string title;
		string author;
		int year;
	public:
		Book(string t, string a, int y);
};

class Person {
	private:
		string name;
	public:
		Person(string name);
		bool hasRead(Book b);
};
