#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Rendering/Tile.h"
#include "Player.h"

class Game
{
	public:
		Game (void);
		~Game (void);
		bool withinRegion (int x, int y, int player);
		void addToRegion (Tile & tile, int player);
		

	private:
		std::vector<Player*> players_;
};

#endif
