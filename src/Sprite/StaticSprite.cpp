#include "StaticSprite.h"
#include <iostream>
#define STATIC_SPRITE_TYPE 0

StaticSprite::StaticSprite (void) {}
		
StaticSprite::StaticSprite (int x, int y, int w, int h):
	SpriteBase(x, y, w, h)
{}

StaticSprite::~StaticSprite (void) {}
		
int StaticSprite::getType (void) const 
{
	return STATIC_SPRITE_TYPE;
}

void StaticSprite::update (void) 
{
	glm::vec2 newPosition = SpriteBase::getPosition() + (SpriteBase::getVelocity() * SpriteBase::getSpeed());
	SpriteBase::setPosition( newPosition );

	if (SpriteBase::canDestroy()) {
		glm::vec2 offset = SpriteBase::getDestruction() - newPosition;
		std::cout << offset.x << std::endl;
		int radius = 7;
		if ((offset.x <= radius && offset.x >= -radius) && (offset.y <= radius && offset.y >= -radius)) {
			SpriteBase::setColor(0, 0, 0, 255);
			SpriteBase::setSize(20, 20);
			SpriteBase::setVelocity(0, 0);
			SpriteBase::setDestroy(false);
		}
	}
}
