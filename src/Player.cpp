#include "Player.h"

Player::Player (void) 
{
	srand (time(NULL));
}

Player::~Player (void) {}		
		
void Player::addBase (Sprite & sprite)
{
	Workspace::addSprite(sprite);
	bases_.push_back(&sprite);
}

void Player::addRegion (Tile & tile)
{
	region_.push_back(&tile);
}
		
std::vector<Sprite*> & Player::getBases (void)
{
	return bases_;
}

std::vector<Tile*> & Player::getRegion (void)
{
	return region_;
}

int Player::totalBases (void)
{
	return bases_.size();
}

void Player::addRandomBase (void)
{
	int index = rand() % region_.size();
	Tile tile = *region_.at(index);
	glm::vec2 position = tile.getPosition();	

	int x = rand() % tile.getWidth() + position.x;
	int y = rand() % tile.getHeight() + position.y;
	int size = 10;

	StaticSprite* sprite = new StaticSprite(x - (size/2), y - (size/2), size, size);
	sprite-> setColor(0, 255, 50, 255);
	Player::addBase(*sprite);
}
