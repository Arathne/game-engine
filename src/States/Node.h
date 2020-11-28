#ifndef NODE_H
#define NODE_H

#include "../Misc/Events.h"
#include "../Rendering/Workspace.h"
#include <iostream>

class Node
{
	public:
		virtual ~Node (void)	{};
		virtual Node* process (void) = 0;
};

#endif
