#include "StaticSprite.h"

#define STATIC_SPRITE_TYPE 0

StaticSprite::StaticSprite (void) {}

StaticSprite::~StaticSprite (void) {}
		
int StaticSprite::getType (void) const 
{
	return STATIC_SPRITE_TYPE;
}

void StaticSprite::update (void) 
{
	glm::vec2 newPosition = SpriteBase::getPosition() + SpriteBase::getVelocity();
	SpriteBase::setPosition( newPosition.x, newPosition.y );
}
