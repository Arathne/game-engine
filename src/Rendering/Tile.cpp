#include "Tile.h"

/* CONSTRUCTORS */

Tile::Tile (void):
	Rectangle(),
	position_(glm::vec2(0, 0))
{}

Tile::Tile (int x, int y, int w, int h, Color color):
	Rectangle(w, h, color),
	position_(glm::vec2(x, y))
{}

Tile::~Tile (void) {}

/* GETTERS */

glm::vec2 Tile::getPosition (void) const
{
	return position_;
}

/* SETTERS */

void Tile::setPosition (int x, int y)
{
	position_ = glm::vec2(x, y);
}
