#ifndef SETUP_PLAYER_H
#define SETUP_PLAYER_H

#include "Node.h"
#include "SetupComputer.h"

class SetupPlayer : public Node
{
	public:
		SetupPlayer (void);
		~SetupPlayer (void);

		Node* process (Game & game);
};

#endif
