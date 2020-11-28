#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

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

	private:
		std::vector<Sprite*> bases_;
		std::vector<Tile*> region_;
};

#endif
