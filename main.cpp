#include <iostream>

#include "GameRenderer.h"
#include "Events.h"

#include "Color.h"
#include "Workspace.h"
#include <glm/glm.hpp>
#include "StaticMap.h"
#include "Texture.h"
#include "StaticSprite.h"

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

int main()
{
	GameRenderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT, "GameEngine");
	
	Texture texture(EPIC_FACE);
	
	StaticSprite person;	
	person.setFrame(texture);	
	person.setVelocity(1, 1);	

	StaticMap level(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	level.linkTexture(texture);
	
	Workspace::addTexture(texture);	
	Workspace::addSprite(person);	
	Workspace::setCurrentMap(level);	
	
	renderer.show();
	
	bool run = true;
	while (run)
	{
		Events::poll();
		if (Events::hasType(SDL_QUIT))
			run = false;
		
		renderer.draw();
	}
}
