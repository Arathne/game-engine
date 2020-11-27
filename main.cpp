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

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

void keyboard (void);
const int speed = 2;

int main()
{
	FPS::setMaxFramerate(60);
	GameRenderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT, "GameEngine");
	
	Texture texture(EPIC_FACE);
	
	TileMap level;
	
	Workspace::addTexture(texture);	
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

/*void keyboard (void)
{
	if (Events::isKeyPressed(SDL_SCANCODE_D)) // d
		person.setVelocityX(speed);
	else {
		if (Events::isKeyPressed(SDL_SCANCODE_A)) // a
			person.setVelocityX(-speed);
		else
			person.setVelocityX(0);
	}
	
	if (Events::isKeyPressed(SDL_SCANCODE_S)) // s
		person.setVelocityY(speed);
	else {
		if (Events::isKeyPressed(SDL_SCANCODE_W)) // w
			person.setVelocityY(-speed);
		else
			person.setVelocityY(0);
	}
}*/
