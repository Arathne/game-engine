#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <glm/glm.hpp>
#include "Color.h"
#include "Texture.h"

class Rectangle
{
	public:
		Rectangle (void);
		Rectangle (int width, int height, Color color);
		~Rectangle (void);
		
		int getHeight (void) const;
		int getWidth (void) const;
		Color getColor (void) const;
		int getTextureId (void) const;
		
		void setSize(int height, int width);
		void setHeight (int height);
		void setWidth (int width);
		void setColor (Color color);

		void setTexture (unsigned int id);
		void setTexture (Texture texture);
		void removeTexture (void);		

	private:
		int height_;
		int width_;
		Color color_;
		unsigned int textureId_;
};

#endif
