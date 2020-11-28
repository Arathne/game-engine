#include "StateManager.h"

StateManager::StateManager (void) 
{
	Setup* setup = new Setup();
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
