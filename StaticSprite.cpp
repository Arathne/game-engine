#include "StaticSprite.h"

unsigned int StaticSprite::objCounter_ = 0;

StaticSprite::StaticSprite (void):
	id_(++objCounter_),
	velocity_(glm::vec2(0,0)),
	acceleration_(glm::vec2(0,0))
{
	StaticSprite::setSize(100, 100);
}

StaticSprite::~StaticSprite (void) {}

void StaticSprite::setFrame (Texture & texture) 
{
	frame_.setTextureId(texture.getId());
}

void StaticSprite::clearFrame (void) 
{
	frame_.setTextureId(0);
}

void StaticSprite::setPosition (int x, int y) 
{
	frame_.setPosition(x, y);
}

void StaticSprite::setVelocity (int dx, int dy) 
{
	velocity_ = glm::vec2(dx, dy);
}

void StaticSprite::setVelocityX (int dx)
{
	velocity_.x = dx;
}

void StaticSprite::setVelocityY (int dy)
{
	velocity_.y = dy;
}

void StaticSprite::setAcceleration (int ddx, int ddy) 
{
	acceleration_ = glm::vec2(ddx, ddy);
}

void StaticSprite::setSize (int w, int h) 
{
	frame_.setSize(w, h);
}
		
glm::vec2 StaticSprite::getPosition (void) 
{
	return frame_.getPosition();
}

glm::vec2 StaticSprite::getVelocity (void) 
{
	return velocity_;
}

glm::vec2 StaticSprite::getAcceleration (void) 
{
	return acceleration_;
}

int StaticSprite::getWidth (void) 
{
	return frame_.getWidth();
}

int StaticSprite::getHeight (void) 
{
	return frame_.getHeight();
}

int StaticSprite::getType (void) const
{
	return 0;
}

unsigned int StaticSprite::getId (void) const
{
	return id_;
}

bool StaticSprite::operator == (const Sprite & rhs)
{
	bool equal = true;
	
	if (getType() != rhs.getType() || id_ != rhs.getId())
		equal = false;		

	return equal;
}

Tile & StaticSprite::getFrame (void)
{
	return frame_;
}

void StaticSprite::update (void)
{
	glm::vec2 newPosition = frame_.getPosition() + velocity_;
	frame_.setPosition(newPosition.x, newPosition.y);
}
