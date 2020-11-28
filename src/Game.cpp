#include "Game.h"

#define BASE_LIMIT 5

Game::Game (void)
{
	Player* player1 = new Player();
	Player* player2 = new Player();

	players_.push_back(player1);
	players_.push_back(player2);
}
		
Game::~Game (void) {}

bool Game::withinRegion (int x, int y, int player)
{
	std::vector<Tile*> region = players_.at(player)-> getRegion();

 	for (auto it = region.begin(); it != region.end(); it++ )
	{
		Tile tile = **it;

		if (tile.getTeam() == player+1) { // must be same team
			glm::vec2 position = tile.getPosition(); 
			if (x >= position.x && x <= position.x + tile.getWidth() ) { // must be within rectangle
				if (y >= position.y && y <= position.y + tile.getHeight() ) {
					return true;
				}
			}
		}
	}

	return false;
}

void Game::addToRegion (Tile & tile, int player)
{
	players_.at(player)-> addRegion(tile);
}

void Game::addBase (Sprite & base, int player)
{
	players_.at(player)-> addBase(base);
}

int Game::totalBases (int player)
{
	return players_.at(player)-> totalBases();
}

bool Game::canAddBases (int player)
{
	return (Game::totalBases(player) < BASE_LIMIT);
}

void Game::addRandomBase (int player)
{
	players_.at(player)-> addRandomBase();
}
