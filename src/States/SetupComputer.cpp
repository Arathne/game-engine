#include "SetupComputer.h"

SetupComputer::SetupComputer (void) {}

SetupComputer::~SetupComputer (void) {}

Node* SetupComputer::process (Game & game)
{
	Node* nextState = this;
	
	while (game.canAddBases(1))
	{
		game.addRandomBase(1);
	}

	return nextState;
}
