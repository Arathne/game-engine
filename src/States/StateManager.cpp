#include "StateManager.h"

StateManager::StateManager (void) 
{
	SetupPlayer* setup = new SetupPlayer();
	state_ = setup;
}

StateManager::~StateManager (void) {}

void StateManager::process (Game & game) 
{
	Node* current = state_;
	state_ = current-> process(game);
	
	if (current != state_)
		delete current;
}	
