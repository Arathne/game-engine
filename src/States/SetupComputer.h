#ifndef SETUP_COMPUTER_H
#define SETUP_COMPUTER_H

#include "Node.h"
#include "War.h"

class SetupComputer : public Node
{
	public:
		SetupComputer (void);
		~SetupComputer (void);

		Node* process (Game & game);
};

#endif
