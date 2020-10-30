#ifndef STATIC_MAP_H
#define STATIC_MAP_H

#include "Map.h"

class StaticMap : public Map
{
	public:
		StaticMap (void);
		StaticMap (int x, int y, int w, int h);
		~StaticMap (void);		
	
		std::vector<Tile*> getTiles (void);		
		
		void linkTexture (Texture & texture);
		void unlinkTexture (void);
	
		glm::vec2 getPosition (void) const;			
		int getHeight (void) const;
		int getWidth (void) const;
		Color getColor	(void) const;

		void setPosition (int x, int y);
		void setSize (int w, int h);
		void setColor (Color color);

	private:
		Tile image_;
};

#endif
