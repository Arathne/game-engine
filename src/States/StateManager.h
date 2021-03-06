#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <vector>

#include "SetupPlayer.h"

class StateManager
{
	public:
		StateManager (void);
		~StateManager (void);

		void process (Game & game);		

	private:
		Node* state_;
};

#endif
