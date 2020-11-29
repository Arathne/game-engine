#ifndef WAR_H
#define WAR_H

#include "Node.h"
#include "../Rendering/Workspace.h"
#include "../Sprite/StaticSprite.h"

class War : public Node
{
	public:
		War (void);
		~War (void);

		Node* process (Game & game);

	private:
		glm::vec2 getMousePosition (void);
		
		glm::vec2 playerPosition_;
		glm::vec2 enemyPosition_;
};

#endif
