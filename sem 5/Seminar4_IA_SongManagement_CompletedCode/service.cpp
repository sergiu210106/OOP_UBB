#include "service.h"

void Service::addItem(std::string artist, std::string title, std::string link, std::string duration, std::string resolution="")
{
	MediaItem* item;
	if (resolution.empty())
		item = new MediaItem(artist, title, link, duration);
	else
		item = new MediaItem(artist, title, link, duration);
	repo.add(item);
}

void Service::removeItem(std::string artist, std::string title)
{
	repo.remove(artist, title);
}

const std::vector<MediaItem*>& Service::get_items()
{
	return repo.get_items();

}
