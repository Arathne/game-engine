#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <iostream>
#include <vector>
#include "Map.h"

class Workspace
{
	public:
		static void setCurrentMap (Map & map);		
		static Map* getCurrentMap (void);		
		static void removeCurrentMap (void);
		
		static void addTexture (Texture & texture);
		static std::vector<Texture*> & getTextures (void);
	
	private:
		static Map* currentMap_;
		static std::vector<Texture*> textures_;
};

#endif
