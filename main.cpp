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

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

void keyboard (void);
const int speed = 2;

StaticSprite person;	

int main()
{
	FPS::setMaxFramerate(60);
	GameRenderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT, "GameEngine");
	
	Texture texture(EPIC_FACE);
	person.setTexture(texture);	
	
	person.setPosition(100, 0);
	TileMap level;
	
	Workspace::addTexture(texture);	
	Workspace::addSprite(person);	
	Workspace::setCurrentMap(level);	
	
	renderer.show();
		
	person.setVelocity(2, 2);
	
	bool run = true;
	while (run)
	{
		Events::poll();
		if (Events::hasType(SDL_QUIT))
			run = false;
		
		//keyboard();

		renderer.draw();
	}
}

void keyboard (void)
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
}
