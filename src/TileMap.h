#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <glm/glm.hpp>
#include <fstream>
#include <iostream>

#include "Tile.h"
#include "Map.h"

class TileMap : public Map
{
	public:
		TileMap (void);		
		TileMap (int tileSize);		
		~TileMap (void);
		
		std::vector<Tile*> getTiles (void);

	private:
		void initializeMap (void);		

		int rows_;
		int columns_;
		int tileSize_;
		
		std::vector<std::vector<Tile>> map_;
};

#endif
