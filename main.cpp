#include <iostream>
#include <glm/glm.hpp>

#include "src/Rendering/GameRenderer.h"
#include "src/Rendering/Workspace.h"
#include "src/Rendering/Texture.h"
#include "src/Sprite/StaticSprite.h"
#include "src/WorldMap.h"
#include "src/Misc/Events.h"
#include "src/Rendering/FPS.h"
#include "src/Misc/Camera.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

Camera camera (122.5, 38, 5);
void keyboard (void);
const int speed = 2;

int main()
{
	GameRenderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT, "GameEngine");
	
	WorldMap level;
	
	Workspace::setCurrentMap(level);	
	Workspace::setCamera(camera);

	renderer.show();
		
	bool run = true;
	while (run)
	{
		Events::poll();
		
		keyboard();
		
		if (Events::hasType(SDL_QUIT))
			run = false;
		
		renderer.draw();
	}
}

void keyboard (void)
{
	if (Events::isKeyPressed(SDL_SCANCODE_D)) // d
		camera.move(RIGHT);
	else {
		if (Events::isKeyPressed(SDL_SCANCODE_A)) // a
			camera.move(LEFT);
	}
	
	if (Events::isKeyPressed(SDL_SCANCODE_S)) // s
		camera.move(DOWN);
	else {
		if (Events::isKeyPressed(SDL_SCANCODE_W)) // w
			camera.move(UP);
	}
}
