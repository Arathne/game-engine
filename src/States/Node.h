#ifndef NODE_H
#define NODE_H

#include <iostream>

#include "../Misc/Events.h"
#include "../Rendering/Workspace.h"
#include "../WorldMap.h"
#include "../Sprite/StaticSprite.h"

class Node
{
	public:
		virtual ~Node (void)	{};
		virtual Node* process (Game & game) = 0;
};

#endif
