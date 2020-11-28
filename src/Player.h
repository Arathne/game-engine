#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Sprite/StaticSprite.h"
#include "Rendering/Tile.h"
#include "Rendering/Workspace.h"

class Player
{
	public:
		Player (void);
		~Player (void);		
		
		void addBase (Sprite & sprite);
		void addRegion (Tile & tile);
		
		std::vector<Sprite*> & getBases (void);
		std::vector<Tile*> & getRegion (void);
		
		int totalBases (void);
		void addRandomBase (void);

	private:
		std::vector<Sprite*> bases_;
		std::vector<Tile*> region_;
};

#endif
