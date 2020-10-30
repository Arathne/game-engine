#include <iostream>

#include "GameRenderer.h"
#include "Events.h"

#include "Color.h"
#include "Workspace.h"
#include <glm/glm.hpp>
#include "StaticMap.h"
#include "Texture.h"

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

int main()
{
	GameRenderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT, "GameEngine");
	
	Texture texture(EPIC_FACE);
	
	Workspace::addTexture(texture);	

	StaticMap level(50, 50, 300, 300);
	level.linkTexture(texture);
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
