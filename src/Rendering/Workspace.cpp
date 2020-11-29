#include "Workspace.h"

Map* Workspace::currentMap_ = nullptr;
Camera* Workspace::camera_;
std::vector<Texture*> Workspace::textures_;
std::vector<Sprite*> Workspace::sprites_;

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
			duplicateFound = true;

		it++;
	}

	if (duplicateFound == false)
		textures_.push_back(&texture);
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

void Workspace::removeTexture (Texture & texture)
{
	bool run = true;
	auto it = textures_.begin();
	
	while( it != textures_.end() && run )
	{
		Texture current = **it;	

		if (current == texture)
		{
			textures_.erase(it);
			run = false;
		}
	}
}	

void Workspace::addSprite (Sprite & sprite)
{
	bool duplicateFound = false;
	
	auto it = sprites_.begin();
	while( it != sprites_.end() && !duplicateFound )
	{
		Sprite* current = *it;

		if (*current == sprite)
			duplicateFound = true;

		it++;
	}

	if (duplicateFound == false) 
		sprites_.push_back(&sprite);
}

void Workspace::removeSprite (Sprite & sprite)
{
	bool run = true;
	auto it = sprites_.begin();
	
	while( it != sprites_.end() && run )
	{
		Sprite* current = *it;	

		if (*current == sprite)
		{
			sprites_.erase(it);
			run = false;
		}
	}

}

std::vector<Sprite*> & Workspace::getSprites (void)
{
 	for (auto it = sprites_.begin(); it != sprites_.end(); it++ )
	{
		if (*it == nullptr)
			sprites_.erase( it-- );
	}
	
	return sprites_;
}

void Workspace::tick (void)
{
	//Collision::check( sprites_ );
	for (auto it = sprites_.begin(); it != sprites_.end(); it++)
	{
		Sprite* current = *it;
		current-> update();
	}
}

void Workspace::setCamera (Camera & camera)
{
	camera_ = &camera;
}

Camera & Workspace::getCamera (void)
{
	return *camera_;
}
