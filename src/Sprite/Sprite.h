#ifndef SPRITE_H
#define SPRITE_H

#include <glm/glm.hpp>

#include "../Rendering/Rectangle.h"
#include "../Rendering/Texture.h"

class Sprite
{
	public:
		virtual ~Sprite (void) {};
		
		/* sprite base handles these */
		virtual glm::vec2 getPosition (void) const = 0;
		virtual glm::vec2 getDirection (void) const = 0;
		virtual glm::vec2 getVelocity (void) const = 0;
		virtual glm::vec2 getSize (void) const = 0;
		virtual void setVelocity (glm::vec2 velocity) = 0;
		virtual void setVelocityX (int dx) = 0;
		virtual void setPosition (glm::vec2 position) = 0;		
		virtual bool isVisible (void) const = 0;	

		virtual Rectangle & getFrame (void) = 0;
		virtual unsigned int getId (void) const = 0;
		virtual bool operator == (const Sprite & rhs) = 0;
		virtual bool operator != (const Sprite & rhs) = 0;
		
		/* every type of sprite needs to implement these two */
		virtual int getType (void) const = 0;
		virtual void update (void) = 0;
};

#endif
