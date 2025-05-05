#include "ui.h"

void UI::showMenu()
{
	std::cout << "1. Add media item" << std::endl;
	std::cout << "2. Remove media item" << std::endl;
	std::cout << "3. Show all media items" << std::endl;
	std::cout << "4. Exit" << std::endl;
}

void UI::addUI()
{
	std::string title, artist, duration, link, resolution="";
	std::cout << "Title: ";
	getchar();

	std::getline(std::cin,title);
	std::cout << "Artist: ";
	std::getline(std::cin, artist);

	std::cout << "Duration (please format: mm:ss): ";
	std::cin >> duration;

	std::cout << "Link: ";
	std::cin >> link;
	getchar();

	std::cout << "Resolution (if not applicable leave empty): ";
	std::getline(std::cin, resolution);

	srv.addItem(artist, title, link, duration, resolution);

}

void UI::removeUI()
{
	std::string artist, title;
	std::cout << "Title: ";
	getchar();
	std::getline(std::cin, title);
	std::cout << "Artist: ";
	std::getline(std::cin, artist);
	srv.removeItem(artist, title);
}

void UI::printAll() const
{
	const auto& all = srv.get_items();
	for ( auto& item : all) {
		std::cout << *item << std::endl;
	}
}

void UI::run()
{
	std::cout << "running";
	int option;
	bool isRunning = true;
	while (isRunning) {
		showMenu();
		std::cout << ">>";
		std::cin >> option;
		switch (option)
		{
		case 1:
			addUI();
			break;
		case 2:
			removeUI();
			break;

		case 3:
			printAll();
			break;
		case 4:
			isRunning = false;
			break;
		}

	}
}
