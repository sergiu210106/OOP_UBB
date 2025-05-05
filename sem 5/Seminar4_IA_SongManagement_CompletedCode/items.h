#pragma once
#include <string>
#include "duration.h"

//MediaItem
//	artist, title, duration, link
//VideoItem
//artist, title, duration, link, resolution

class MediaItem
{
protected:
	std::string artist = "";
	std::string title = "";
	std::string link = "";
	Duration duration = Duration("0:0");
public:
	MediaItem() = default;
	MediaItem(std::string artist, std::string title, std::string link, Duration duration) :artist(artist), title(title), link(link), duration(duration) {}
	MediaItem(std::string artist, std::string title, std::string link, std::string duration) :artist(artist), title(title), link(link), duration(duration) {}
	MediaItem(std::string artist, std::string title, std::string link, int minutes, int seconds) :artist(artist), title(title), link(link), duration(minutes, seconds) {}


	std::string getArtist() const;
	std::string getTitle() const;
	std::string getLink() const;
	Duration getDuration() const;

	void setArtist(std::string newArtist);
	void setTitle(std::string newTitle);
	void setLink(std::string newLink);
	void setDuration(Duration newDuration);

	virtual std::string toString() const;

	friend std::ostream& operator<<(std::ostream&, const MediaItem& item);
	virtual ~MediaItem() = default;
};

class VideoItem : public MediaItem
{
private:
	std::string resolution = "";
public:
	VideoItem() = default;
	VideoItem(std::string artist, std::string title, std::string link, std::string duration, std::string resolution) :MediaItem
	{ artist, title, link, duration }, resolution{ resolution } {}
	std::string toString() const override;
	~VideoItem() = default;
};