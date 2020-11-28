#include "Setup.h"

Setup::Setup (void)
{}

Setup::~Setup (void) {}

Node* Setup::process (void)
{
	
	if (Events::hasType(SDL_MOUSEBUTTONDOWN)) {
		int x;
		int y;
		Events::getMousePosition(&x, &y);
		
		Camera camera = Workspace::getCamera();
		glm::mat3 transform = glm::inverse(camera.getTransform());
		
		glm::vec3 position = transform * glm::vec3(x, y, 1);
		
		std::cout << position.x << "   " << position.y << std::endl;
	}
		
	return this;
}
