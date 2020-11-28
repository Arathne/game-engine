#include "WorldMap.h"

#define DEFAULT_ROWS 0
#define DEFAULT_COLUMNS 0
#define DEFAULT_TILE_SIZE 23

WorldMap::WorldMap():
	rows_(DEFAULT_ROWS),
	columns_(DEFAULT_COLUMNS),
	tileSize_(DEFAULT_TILE_SIZE)
{}

WorldMap::~WorldMap() {}

void WorldMap::initializeMap (Game & game)
{
	std::ifstream textureBuffer;
	std::ifstream teamBuffer;
	
	textureBuffer.open(MAP_TID);
	teamBuffer.open(MAP_TM);
	
	teamBuffer >> rows_;
	teamBuffer >> columns_;
	
	map_.resize(rows_, std::vector<Tile>(columns_));
	
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < columns_; j++) {
			int texture;
			int team;
			
			textureBuffer >> texture;			
			teamBuffer >> team;			

			map_[i][j].setPosition(j*tileSize_, i*tileSize_);
			map_[i][j].setSize(tileSize_, tileSize_);
			map_[i][j].setTexture(texture);
			map_[i][j].setTeam(team);			

			if (team == 1) {
				map_[i][j].setColor(Color::make(0,0,255,255));
				game.addToRegion(map_[i][j], 0);
			}
			else if (team == 2) {
				map_[i][j].setColor(Color::make(255,0,0,255));
				game.addToRegion(map_[i][j], 1);
			}
		}
	}
}

std::vector<Tile*> WorldMap::getTiles (void)
{
	std::vector<Tile*> tiles;
	
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < columns_; j++) {
			if (map_[i][j].getTextureId() > 0)
				tiles.push_back(&map_[i][j]);
		}
	}

	return tiles;
}
