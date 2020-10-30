#include "Tile.h"

Tile::Tile (void):
	position_(glm::vec2(0, 0)),
	height_(10),
	width_(10),
	color_(Color::make(0, 0, 150, 255)),
	textureId_(0)
{}

Tile::Tile (int x, int y, int w, int h, Color color):
	position_(glm::vec2(x, y)),
	height_(h),
	width_(w),
	color_(color),
	textureId_(0)
{}

Tile::~Tile (void) {}

glm::vec2 Tile::getPosition (void) const
{
	return position_;
}		
		
int Tile::getHeight (void) const 
{
	return height_;
}
		
int Tile::getWidth (void) const
{
	return width_;
}

Color Tile::getColor	(void) const
{
	return color_;
}

int Tile::getTextureId (void) const
{
	return textureId_;
}

void Tile::setPosition (int x, int y)
{
	position_ = glm::vec2(x, y);
}

void Tile::setSize (int w, int h)
{
	width_ = w;
	height_ = h;
}

void Tile::setColor (Color color)
{
	color_ = color;
}

void Tile::setTextureId (int id)
{
	textureId_ = id;
}
