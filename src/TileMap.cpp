#include "TileMap.h"

#define DEFAULT_ROWS 0
#define DEFAULT_COLUMNS 0
#define DEFAULT_TILE_SIZE 23

TileMap::TileMap():
	rows_(DEFAULT_ROWS),
	columns_(DEFAULT_COLUMNS),
	tileSize_(DEFAULT_TILE_SIZE)
{
	TileMap::initializeMap();
}

TileMap::TileMap (int tileSize): 
	tileSize_(tileSize)
{
	TileMap::initializeMap();
}

TileMap::~TileMap() {}

void TileMap::initializeMap (void)
{
	std::ifstream buffer;
	
	buffer.open(MAP_TID);
	buffer >> rows_;
	buffer >> columns_;
	
	map_.resize(rows_, std::vector<Tile>(columns_));
	
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < columns_; j++) {
			int data;
			buffer >> data;			

			map_[i][j].setPosition(j*tileSize_, i*tileSize_);
			map_[i][j].setSize(tileSize_, tileSize_);
			map_[i][j].setTexture(data);
			
			if (data == 1)
				map_[i][j].setColor(Color::make(0,0,255,255));
			else if (data == 2)
				map_[i][j].setColor(Color::make(255,0,0,255));
		}
	}
}

std::vector<Tile*> TileMap::getTiles (void)
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
