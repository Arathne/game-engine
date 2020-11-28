#include "Player.h"

Player::Player (void) {}

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
