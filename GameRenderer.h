#ifndef GAMERENDERER_H
#define GAMERENDERER_H

#include <SDL2/SDL.h>
#include <stdexcept>
#include <vector>

#include "Workspace.h"
#include "Map.h"
#include "Tile.h"
#include "Scene.h"
#include "Color.h"

class GameRenderer
{
	public:
		GameRenderer (void);	
		GameRenderer (unsigned int w, unsigned int h, const char* windowTitle);
		~GameRenderer (void);
		
		void show (void);
		void hide (void);
		void draw (void);

	private:
		void init (unsigned int w, unsigned int h, const char* windowTitle);
		void drawMap (void);		
		
		SDL_Window* window_;
		SDL_Renderer* renderer_;
};

#endif
