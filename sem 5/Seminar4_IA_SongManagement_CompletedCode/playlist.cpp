#include "playlist.h"

void Playlist::addMultipleItems(std::vector<MediaItem*> itemsToAdd) {
    playlist.insert(playlist.begin(), playlist.end(), itemsToAdd);
}

std::vector<MediaItem*> Playlist::getAll() const {
    return playlist;   
}