#include "SpriteBase.h"

unsigned int SpriteBase::spriteIdCounter_ = 0;

SpriteBase::SpriteBase (void):
	id_ (++spriteIdCounter_),
	visible_ (true),
	position_ (glm::vec2(0, 0)),
	velocity_ (glm::vec2(0, 0)),
	acceleration_ (glm::vec2(0, 0)),
	direction_ (glm::vec2(0, 0))
{}

SpriteBase::SpriteBase (int x, int y, int w, int h):
	id_ (++spriteIdCounter_),
	visible_ (true),
	position_ (glm::vec2(x, y)),
	velocity_ (glm::vec2(0, 0)),
	acceleration_ (glm::vec2(0, 0)),
	direction_ (glm::vec2(0, 0)),
	speed_ (1.0f)
{
	frame_.setSize(w, h);
}


SpriteBase::~SpriteBase (void) {}

/* GETTERS */

glm::vec2 SpriteBase::getPosition (void) const
{
	return position_;
}
		
glm::vec2 SpriteBase::getVelocity (void) const
{
	return velocity_;
}

glm::vec2 SpriteBase::getAcceleration (void)	const
{
	return acceleration_;
}

glm::vec2 SpriteBase::getSize (void) const
{
	return frame_.getSize();
}

unsigned int SpriteBase::getId (void) const
{
	return id_;
}

bool SpriteBase::isVisible (void) const
{
	return visible_;
}	

glm::vec2 SpriteBase::getDirection (void) const 
{
	return direction_;
}

float SpriteBase::getSpeed (void) const
{
	return speed_;
}

/* SETTERS */

void SpriteBase::setSize (int w, int h)
{
	frame_.setSize(w, h);
}

void SpriteBase::setHeight (int h)
{
	frame_.setHeight(h);
}

void SpriteBase::setWidth (int w)
{
	frame_.setWidth(w);
}

void SpriteBase::setPosition (glm::vec2 position) 
{
	position_ = position;
}

void SpriteBase::setPosition (int x, int y)
{
	position_ = glm::vec2(x, y);
}

void SpriteBase::setPositionX (int x)
{
	position_.x = x;
}

void SpriteBase::setPositionY (int y)
{
	position_.y = y;
}

void SpriteBase::setVelocity (glm::vec2 velocity) 
{
	velocity_ = velocity;
}

void SpriteBase::setVelocity (int dx, int dy)
{
	velocity_ = glm::vec2(dx, dy);
}

void SpriteBase::setVelocityX (int dx)
{
	velocity_.x = dx;
}

void SpriteBase::setVelocityY (int dy)
{
	velocity_.y = dy;
}
		
void SpriteBase::setAcceleration (int ddx, int ddy)
{
	acceleration_ = glm::vec2(ddx, ddy);
}

void SpriteBase::setAccelerationX (int ddx)
{
	acceleration_.x = ddx;
}

void SpriteBase::setAccelerationY (int ddy) 
{
	acceleration_.y = ddy;
}
		
void SpriteBase::setVisible (bool visible)
{
	visible_ = visible;
}
		
void SpriteBase::setDirection (glm::vec2 direction)
{
	direction_ = direction;
	velocity_ = glm::normalize(direction);
}	

void SpriteBase::setColor (int r, int g, int b, int a)
{
	frame_.setColor(r, g, b, a);
}

void SpriteBase::setSpeed (float speed)
{
	speed_ = speed;
}
			

/* TEXTURES */

void SpriteBase::setTexture (Texture & texture)
{
	frame_.setTexture( texture );
}

void SpriteBase::clearTexture (void)
{
	frame_.removeTexture();
}

Rectangle & SpriteBase::getFrame (void)
{
	return frame_;
}

/* OPERATOR OVERLOADING */

bool SpriteBase::operator == (const Sprite & rhs)
{
	if (getType() != rhs.getType() || id_ != rhs.getId())
		return false;

	return true;
}

bool SpriteBase::operator != (const Sprite & rhs)
{
	return !(*this == rhs);
}
