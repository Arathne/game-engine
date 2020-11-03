#include "Rectangle.h"

/* CONSTRUCTORS */

Rectangle::Rectangle (void):
	height_ (50),
	width_ (50),
	color_ (Color::make(0, 255, 0, 255)),
	textureId_(0)
{}

Rectangle::Rectangle (int width, int height, Color color):
	height_ (height),
	width_ (width),
	color_ (color),
	textureId_ (0)
{}

Rectangle::~Rectangle (void) {}

/* GETTERS */

int Rectangle::getHeight (void) const
{
	return height_;
}

int Rectangle::getWidth (void) const
{
	return width_;
}

Color Rectangle::getColor (void) const
{
	return color_;
}

int Rectangle::getTextureId (void) const
{
	return textureId_;
}

/* SETTERS */

void Rectangle::setSize(int height, int width)
{
	height_ = height;
	width_ = width;
}

void Rectangle::setHeight (int height)
{
	height_ = height;
}

void Rectangle::setWidth (int width)
{
	width_ = width;
}

void Rectangle::setColor (Color color)
{
	color_ = color;
}

void Rectangle::setTexture (unsigned int id)
{
	textureId_ = id;
}

void Rectangle::setTexture (Texture texture)
{
	textureId_ = texture.getId();
}

void Rectangle::removeTexture (void)
{
	textureId_ = 0;
}
