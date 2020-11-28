#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <vector>

#include "Setup.h"

class StateManager
{
	public:
		StateManager (void);
		~StateManager (void);

		void process (void);		

	private:
		Node* state_;
};

#endif
