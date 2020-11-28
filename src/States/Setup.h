#ifndef SETUP_H
#define SETUP_H

#include "Node.h"

class Setup : public Node
{
	public:
		Setup (void);
		~Setup (void);

		Node* process (Game & game);
};

#endif
