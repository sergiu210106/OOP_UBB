#pragma once
#include "repo.h"
class Service {
private:
	Repository& repo;
public:
	Service(Repository& repo) :repo{ repo } {};
	void addItem(std::string artist, std::string title, std::string link, std::string duration, std::string resolution);

	void removeItem(std::string artist, std::string title);
	const std::vector<MediaItem*>& get_items();
};