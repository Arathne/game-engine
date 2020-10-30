#ifndef TILE_H
#define TILE_H

#include <glm/glm.hpp>
#include "Color.h"

class Tile
{
	public:
		Tile (void);
		Tile (int x, int y, int w, int h, Color color);
		~Tile (void);		
	
		glm::vec2 getPosition (void) const;			
		int getHeight (void) const;
		int getWidth (void) const;
		Color getColor	(void) const;
		int getTextureId (void) const;

		void setPosition (int x, int y);
		void setSize (int w, int h);
		void setColor (Color color);
		void setTextureId (int id);

	private:
		glm::vec2 position_;
		int height_;
		int width_;
		Color color_;
		int textureId_;
};

#endif
