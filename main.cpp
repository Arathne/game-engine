#include <iostream>

#include "GameRenderer.h"
#include "Events.h"

#include "Color.h"
#include "Workspace.h"

#include <glm/glm.hpp>

#include "StaticMap.h"

int main()
{
	GameRenderer renderer(500, 500, "Hello World");
	
	Workspace workspace;
	
	StaticMap level(50, 50, 300, 300);
	workspace.setCurrentMap(level);	

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
