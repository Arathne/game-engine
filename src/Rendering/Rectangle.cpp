#include "Rectangle.h"

/* CONSTRUCTORS */

Rectangle::Rectangle (void):
	height_ (100),
	width_ (100),
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

glm::vec2 Rectangle::getSize (void) const
{
	return glm::vec2(width_, height_);
}

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

void Rectangle::setColor (int r, int g, int b, int a)
{
	color_ = Color::make(r, g, b, a);
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
