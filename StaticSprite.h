#ifndef STATIC_SPRITE_H
#define STATIC_SPRITE_H

#include "Sprite.h"

class StaticSprite : public Sprite
{
	public:
		StaticSprite (void);
		~StaticSprite (void);
		
		void setFrame (Texture & texture);
		void clearFrame (void);
      
		void setPosition (int x, int y);
		void setVelocity (int dx, int dy);
		void setAcceleration (int ddx, int ddy);
		void setSize (int w, int h);
		
		glm::vec2 getPosition (void);
		glm::vec2 getVelocity (void);
		glm::vec2 getAcceleration (void);
		int getWidth (void);
		int getHeight (void);
		
		Tile & getFrame (void);
		int getType (void) const;
		unsigned int getId (void) const;
		bool operator == (const Sprite & rhs);
		void update (void);		

	private:
		static unsigned int objCounter_;
		unsigned int id_;
		Tile frame_;
		glm::vec2 velocity_;
		glm::vec2 acceleration_;	
};

#endif
