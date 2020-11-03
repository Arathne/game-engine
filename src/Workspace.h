#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <vector>
#include "Map.h"
#include "Sprite.h"
#include <iostream>

class Workspace
{
	public:
		static void setCurrentMap (Map & map);		
		static Map* getCurrentMap (void);		
		static void removeCurrentMap (void);
		
		static void addTexture (Texture & texture);
		static std::vector<Texture*> & getTextures (void);
		static void removeTexture (Texture & texture);		
		
		static void addSprite (Sprite & sprite);
		static void removeSprite (Sprite & sprite);
		static std::vector<Sprite*> & getSprites (void);
		
		static void tick (void);		

	private:
		static Map* currentMap_;
		static std::vector<Texture*> textures_;
		static std::vector<Sprite*> sprites_;
};

#endif
