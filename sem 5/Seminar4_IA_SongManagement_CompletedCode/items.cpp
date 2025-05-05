#include "items.h"

std::string MediaItem::getArtist() const {
	return this->artist;
}
std::string MediaItem::getTitle() const {
	return this->title;
}
std::string MediaItem::getLink() const {
	return this->link;
}
Duration MediaItem::getDuration() const {
	return this->duration;
}

void MediaItem::setArtist(std::string newArtist) {
	this->artist = newArtist;
}
void MediaItem::setTitle(std::string newTitle) {
	this->title = newTitle;
}
void MediaItem::setLink(std::string newLink) {
	this->link = newLink;
}
void MediaItem::setDuration(Duration newDuration) {
	this->duration = newDuration;
}

std::string MediaItem::toString() const
{
	return artist + ";" +title + ";" + duration.toString() + ";" + link;

}

std::string VideoItem::toString() const
{
	return MediaItem::toString() + ";" + resolution;
}

std::ostream& operator<<(std::ostream& out, const MediaItem& item)
{
	out << item.toString();
	return out;
}
