#ifndef SCENE_H
#define SCENE_H

#include "Color.h"

class Scene
{
	public:
		Scene (void);
		Scene (Color color);
		~Scene (void);

		void show (void);
		void hide (void);
		bool isVisible (void) const;
		
		Color getColor (void) const;

	private:
		bool visible_;
		Color color_;
		
};

#endif
