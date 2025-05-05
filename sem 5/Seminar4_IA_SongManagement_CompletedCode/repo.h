#pragma once
#include<vector>
#include <fstream>
#include "items.h"
#include "utils.h"
class Repository {

	std::vector <MediaItem*> items;
public:
	virtual void add(MediaItem* item);
	virtual void remove(std::string artist, std::string title);

	const std::vector<MediaItem*>& get_items() const;
	virtual ~Repository() {
		for (auto item : items) {
			delete item;
		}
	};
};

class RepositoryFile :public Repository {
private:
	std::string filename;
	void loadFromFile();
	void saveToFile();
public:
	RepositoryFile(std::string file) :filename{ file } {
		loadFromFile();
		std::cout << Repository::get_items().size() << std::endl;
	}
	void add(MediaItem* item) override;
	void remove(std::string artist,std::string title) override;
	~RepositoryFile() = default;
};