#include "StaticSprite.h"

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
}
