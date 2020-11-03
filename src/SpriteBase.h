#ifndef SPRITE_BASE_H
#define SPRITE_BASE_H

#include <glm/glm.hpp>
#include "Sprite.h"

class SpriteBase : public Sprite
{
	public:
		SpriteBase (void);
		~SpriteBase (void);
		
		glm::vec2 getPosition (void) const;
		glm::vec2 getVelocity (void) const;		
		glm::vec2 getAcceleration (void)	const;	
		glm::vec2 getSize (void) const;		
		bool isVisible (void) const;	
		unsigned int getId (void) const;

		void setSize (int w, int h);
		void setHeight (int h);
		void setWidth (int w);

		void setPosition (int x, int y);
		void setPositionX (int x);
		void setPositionY (int y);

		void setVelocity (int dx, int dy);
		void setVelocityX (int dx);
		void setVelocityY (int dy);
		
		void setAcceleration (int ddx, int ddy);
		void setAccelerationX (int ddx);
		void setAccelerationY (int ddy);
		
		void setVisible (bool visible);
		
		void setTexture (Texture & texture);
		void clearTexture (void);
		Rectangle & getFrame (void);
		
		bool operator == (const Sprite & rhs);

	private:
		static unsigned int spriteIdCounter_;
		unsigned int id_;
		
		Rectangle frame_;

		bool visible_;
		glm::vec2 position_;
		glm::vec2 velocity_;
		glm::vec2 acceleration_;
};

#endif
