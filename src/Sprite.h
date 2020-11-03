#ifndef SPRITE_H
#define SPRITE_H

#include "Rectangle.h"
#include "Texture.h"
#include <glm/glm.hpp>

class Sprite
{
	public:
		virtual ~Sprite (void) {};
		
		/* sprite base handles these */
		virtual glm::vec2 getPosition (void) const = 0;
		virtual Rectangle & getFrame (void) = 0;
		virtual unsigned int getId (void) const = 0;
		virtual bool operator == (const Sprite & rhs) = 0;
		
		/* every type of sprite needs to implement these two */
		virtual int getType (void) const = 0;
		virtual void update (void) = 0;
};

#endif
