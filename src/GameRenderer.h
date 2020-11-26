#ifndef GAMERENDERER_H
#define GAMERENDERER_H

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdexcept>
#include <vector>

#include "Workspace.h"
#include "FPS.h"
#include "Texture.h"
#include "Map.h"
#include "Rectangle.h"
#include "Tile.h"
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
		void drawSprites (void) const;		
	
		void checkTextures (void);
		void loadTexture (Texture & texture);
		bool isTextureInWorkspace (Texture & texture) const;
		bool isTextureInRenderer (Texture & texture) const;
		int getTextureIndex (unsigned int id) const;

		SDL_Window* window_;
		SDL_Renderer* renderer_;
		std::vector<SDL_Texture*> loadedTextures_;
		std::vector<Texture*> textures_;
};

#endif
