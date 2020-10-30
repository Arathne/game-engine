#include "StaticMap.h"

StaticMap::StaticMap (void) 
{}

StaticMap::StaticMap (int x, int y, int w, int h):
	image_(x, y, w, h, Color::make(0,0,255,255))
{}

StaticMap::~StaticMap (void) {}
		
std::vector<Tile*> StaticMap::getTiles (void)
{
	std::vector<Tile*> tiles;
	tiles.push_back(&image_);
	return tiles;
}

void StaticMap::linkTexture (Texture & texture)
{
	image_.setTextureId(texture.getId());
}

void StaticMap::unlinkTexture (void)
{
	image_.setTextureId(0);
}

		
glm::vec2 StaticMap::getPosition (void) const
{
	return image_.getPosition();
}		

int StaticMap::getHeight (void) const
{
	return image_.getHeight();
}

int StaticMap::getWidth (void) const
{
	return image_.getWidth();
}

Color StaticMap::getColor (void) const
{
	return image_.getColor();
}

void StaticMap::setPosition (int x, int y)
{
	image_.setPosition(x, y);
}

void StaticMap::setSize (int w, int h)
{
	image_.setSize(w, h);
}

void StaticMap::setColor (Color color) 
{
	image_.setColor(color);
}
