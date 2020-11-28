#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#include <glm/glm.hpp>
#include <fstream>
#include <iostream>

#include "Rendering/Tile.h"
#include "Rendering/Map.h"
#include "Game.h"

class WorldMap : public Map
{
	public:
		WorldMap (void);		
		~WorldMap (void);
		
		std::vector<Tile*> getTiles (void);
		void initializeMap (Game & game);		
	
	private:
		int rows_;
		int columns_;
		int tileSize_;
		
		std::vector<std::vector<Tile>> map_;
};

#endif
