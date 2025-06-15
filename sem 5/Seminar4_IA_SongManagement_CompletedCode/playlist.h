#include <vector>
#include "items.h"   
class Playlist {
	private:
		std::vector<MediaItem*> playlist;
	public:
		void add(MediaItem* item);
		void addMultipleItems(std::vector<MediaItem*> itemsToAdd);
		std::vector<MediaItem*> getAll() const;
};