#include <iostream>
#include <glm/glm.hpp>

#include "src/GameRenderer.h"
#include "src/Color.h"
#include "src/Workspace.h"
#include "src/StaticMap.h"
#include "src/TileMap.h"
#include "src/Texture.h"
#include "src/StaticSprite.h"
#include "src/Tile.h"
#include "src/Events.h"

#include "src/FPS.h"
#include "src/Camera.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

Camera camera (157, 38, 5);
void keyboard (void);
const int speed = 2;

int main()
{
	FPS::setMaxFramerate(60);
	GameRenderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT, "GameEngine");
	
	Texture texture(EPIC_FACE);
	
	TileMap level;
	
	//Workspace::addTexture(texture);	
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
