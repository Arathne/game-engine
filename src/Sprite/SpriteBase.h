#ifndef SPRITE_BASE_H
#define SPRITE_BASE_H

#include "Sprite.h"

class SpriteBase : public Sprite
{
	public:
		SpriteBase (void);
		SpriteBase (int x, int y, int w, int h);
		~SpriteBase (void);
		
		glm::vec2 getPosition (void) const;
		glm::vec2 getVelocity (void) const;		
		glm::vec2 getAcceleration (void)	const;	
		glm::vec2 getSize (void) const;
		glm::vec2 getDirection (void) const;
		float getSpeed (void) const;

		unsigned int getId (void) const;
		bool isVisible (void) const;	

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
		
		void setDirection (glm::vec2 direction);	
		
		void setVisible (bool visible);
		
		void setTexture (Texture & texture);
		void clearTexture (void);
		Rectangle & getFrame (void);
		
		bool operator == (const Sprite & rhs);
		bool operator != (const Sprite & rhs);
		
		void setVelocity (glm::vec2 velocity);
		void setPosition (glm::vec2 position);		
		void setColor (int r, int g, int b, int a);		
		void setSpeed (float speed);
		
	private:
		static unsigned int spriteIdCounter_;
		unsigned int id_;
		
		Rectangle frame_;

		bool visible_;

		glm::vec2 position_;
		glm::vec2 velocity_;
		glm::vec2 acceleration_;
		glm::vec2 direction_;
		float speed_;
};

#endif
