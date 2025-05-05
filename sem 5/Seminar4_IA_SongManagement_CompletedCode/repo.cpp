#include "repo.h"
#include <algorithm>

void Repository::add(MediaItem* item) {
	items.push_back(item);
}
void Repository::remove(std::string artist, std::string title)
{
	items.erase(std::remove_if(items.begin(), items.end(), [&](MediaItem* item) {
		return item->getArtist() == artist && item->getTitle() == title;
		
		}), items.end());

}
const std::vector<MediaItem*>& Repository::get_items()const {
	return items;
}

void RepositoryFile::loadFromFile()
{
	std::ifstream file(filename);
	//Led Zeppelin;Stairway to Heaven;8:2; https://www.youtube.com/watch?v=QkF3oxziUI4
	std::string line;
	while (std::getline(file, line)) {
		std::vector<std::string> tokens = StringUtils::split(line, ';');
		MediaItem* item;
		if (tokens.size() == 4) {
			std::cout << "Added media item" << std::endl;
			item = new MediaItem(tokens[0], tokens[1], tokens[3], tokens[2]);
		}
		else {
			std::cout << "Added video item" << tokens.size()<< std::endl;
			item = new VideoItem(tokens[0], tokens[1], tokens[3], tokens[2], tokens[4]);
		}
		Repository::add(item);
		
	}
	file.close();

}

void RepositoryFile::saveToFile()
{
	std::ofstream file(filename);
	for (const auto& item : Repository::get_items()) {
		file << item->toString();
		file << '\n';
	}
	file.close();

}

void RepositoryFile::add(MediaItem* item)
{
	Repository::add(item);
	saveToFile();
}

void RepositoryFile::remove(std::string artist, std::string title)
{
	std::cout << artist << " " << title << std::endl;
	Repository::remove(artist, title);
	saveToFile();
}

class UndoAction {
	public:
		virtual void execute() = 0;
		virtual ~UndoAction() = default;

};	

class UndoAdd : public UndoAction {
	private:
		MediaItem* item;
		Repository& repo;

	public:
		void execute() override {
			repo.remove(item->getArtist(),item->getTitle());
		}
};

class UndoRemove : public UndoAction {

};

