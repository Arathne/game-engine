#ifndef SPRITE_H
#define SPRITE_H

#include "Tile.h"
#include "Texture.h"
#include <glm/glm.hpp>

class Sprite
{
	public:
		virtual ~Sprite (void) {};
		virtual Tile & getFrame (void) = 0;
		virtual int getType (void) const = 0;
		virtual unsigned int getId (void) const = 0;
		virtual bool operator == (const Sprite & rhs) = 0;
		virtual void update (void) = 0;
};

#endif
