#ifndef MAP_H
#define MAP_H

#include "Tile.h"
#include "Texture.h"
#include <vector>

class Map
{
	public:
		virtual ~Map (void) {};
		virtual std::vector<Tile*> getTiles (void) = 0;
};

#endif
