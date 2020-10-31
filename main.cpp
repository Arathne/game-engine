#include <iostream>

#include "GameRenderer.h"
#include "Events.h"

#include "Color.h"
#include "Workspace.h"
#include <glm/glm.hpp>
#include "StaticMap.h"
#include "Texture.h"
#include "StaticSprite.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

void keyboard (void);

StaticSprite person;	

int main()
{
	GameRenderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT, "GameEngine");
	
	Texture texture(EPIC_FACE);
	person.setPosition(WINDOW_WIDTH/2-50, WINDOW_HEIGHT/2-50);
	person.setFrame(texture);	

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
		
		keyboard();

		renderer.draw();
	}
}

void keyboard (void)
{
	if (Events::isKeyPressed(100)) // d
		person.setVelocityX(1);
	else {
		if (Events::isKeyPressed(97)) // a
			person.setVelocityX(-1);
		else
			person.setVelocityX(0);
	}
	
	if (Events::isKeyPressed(115)) // s
		person.setVelocityY(1);
	else {
		if (Events::isKeyPressed(119)) // w
			person.setVelocityY(-1);
		else
			person.setVelocityY(0);
	}
}
