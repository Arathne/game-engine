#include "SetupPlayer.h"

SetupPlayer::SetupPlayer (void)
{}

SetupPlayer::~SetupPlayer (void) {}

Node* SetupPlayer::process (Game & game)
{
	Node* nextState = this;
	bool canAdd = game.canAddBases(0);

	if (Events::hasType(SDL_MOUSEBUTTONDOWN) && canAdd) {
		int x;
		int y;
		Events::getMousePosition(&x, &y);
		
		Camera camera = Workspace::getCamera();
		
		glm::mat3 transform = glm::inverse(camera.getTransform());
		glm::vec3 position = transform * glm::vec3(x, y, 1);
		
		bool isClickInRegion = game.withinRegion(position.x, position.y, 0);
		
		if (isClickInRegion) {
			int size = 10;
			StaticSprite* sprite = new StaticSprite(position.x - (size/2), position.y - (size/2), size, size);
			game.addBase(*sprite, 0);
		}	
	}

	if (canAdd == false) {
		nextState = new SetupComputer();
		std::cout << "state change :: computer picking bases" << std::endl; 
	}
				
	return nextState;
}
