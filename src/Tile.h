#ifndef TILE_H
#define TILE_H

#include "Rectangle.h"

class Tile : public Rectangle
{
	public:
		Tile (void);
		Tile (int x, int y, int w, int h, Color color);
		~Tile (void);		
	
		glm::vec2 getPosition (void) const;			
		void setPosition (int x, int y);

	private:
		glm::vec2 position_;
};

#endif
