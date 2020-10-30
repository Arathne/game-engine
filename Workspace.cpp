#include "Workspace.h"

Map* Workspace::currentMap_ = nullptr;
std::vector<Texture*> Workspace::textures_;

void Workspace::setCurrentMap (Map & map)
{
	currentMap_ = &map;
}

Map * Workspace::getCurrentMap (void)
{
	return currentMap_;
}		

void Workspace::removeCurrentMap (void)
{
	currentMap_ = nullptr;
}

void Workspace::addTexture (Texture & texture)
{	
	bool duplicateFound = false;
	
	auto it = textures_.begin();
	while( it != textures_.end() && !duplicateFound )
	{
		Texture current = **it;	

		if (current == texture)
		{
			std::cout << "DUPLICATE FOUND" << std::endl;
			duplicateFound = true;
		}

		it++;
	}

	if (duplicateFound == false){
		std::cout << "added texture to array" << std::endl;
		textures_.push_back(&texture);
	}
}

std::vector<Texture*> & Workspace::getTextures (void)
{
 	for (auto it = textures_.begin(); it != textures_.end(); it++ )
	{
		if (*it == nullptr)
			textures_.erase( it-- );
	}

	return textures_;
}
