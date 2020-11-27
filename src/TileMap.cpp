#include "TileMap.h"

#define DEFAULT_ROWS 6
#define DEFAULT_COLUMNS 5
#define DEFAULT_TILE_SIZE 100

TileMap::TileMap():
	rows_(DEFAULT_ROWS),
	columns_(DEFAULT_COLUMNS),
	tileSize_(DEFAULT_TILE_SIZE)
{
	TileMap::initializeMap();
	TileMap::generate();
}

TileMap::TileMap (int row, int col, int tileSize):
	rows_(row),
	columns_(col),
	tileSize_(tileSize)
{
	TileMap::initializeMap();
	TileMap::generate();
}

TileMap::~TileMap() {}

void TileMap::initializeMap (void)
{
	map_.resize(rows_, std::vector<Tile>(columns_));

	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < columns_; j++) {
			map_[i][j].setPosition(i*tileSize_, j*tileSize_);
			map_[i][j].setSize(tileSize_, tileSize_);

			if (i % 2 == 0 && j % 2 == 0)
				map_[i][j].setColor(Color::make(255, 0, 255, 255));
			else
				map_[i][j].setColor(Color::make(50, 0, 100, 255));
		}
	}
}


void TileMap::generate (void)
{
	TileMap::initializeMap();
}

std::vector<Tile*> TileMap::getTiles (void)
{
	std::vector<Tile*> tiles;
	
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < columns_; j++) {
			tiles.push_back(&map_[i][j]);
		}
	}

	return tiles;
}
