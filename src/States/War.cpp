#include "War.h"

War::War (void):
	playerPosition_(glm::vec2(-86, -86)),
	enemyPosition_(glm::vec2(-86, -86))
{}

War::~War (void) {}

Node* War::process (Game & game)
{
	Node* nextState = this;
	
	if (Events::hasType(SDL_MOUSEBUTTONDOWN)) {
		glm::vec2 position = War::getMousePosition();
		
		bool isClickInPlayerRegion = game.withinRegion(position.x, position.y, 0);
		bool isClickInEnemyRegion = game.withinRegion(position.x, position.y, 1);
		
		if (isClickInPlayerRegion) {
			playerPosition_ = position;
			std::cout << "home region selected" << std::endl;
		}
		else if (isClickInEnemyRegion) {
			enemyPosition_ = position;
			std::cout << "enemy region selected" << std::endl;
		}
		
		if (playerPosition_.x != -86 && enemyPosition_.x != -86)	{
			glm::vec2 direction = enemyPosition_ - playerPosition_;

			StaticSprite* sprite = new StaticSprite(playerPosition_.x, playerPosition_.y, 8, 8);			
			sprite-> setDirection(direction);
			sprite-> setSpeed(2.0f);
			sprite-> selfDestruct(enemyPosition_);
			Workspace::addSprite(*sprite);			

			playerPosition_.x = -86;
			enemyPosition_.x = -86;
		}
	}

	return nextState;
}

glm::vec2 War::getMousePosition (void)
{
	int x;
	int y;
	Events::getMousePosition(&x, &y);
		
	Camera camera = Workspace::getCamera();
	glm::mat3 transform = glm::inverse(camera.getTransform());
	glm::vec3 position = transform * glm::vec3(x, y, 1);

	return glm::vec2(position.x, position.y);
}
