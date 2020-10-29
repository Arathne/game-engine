#include "Events.h"

std::vector<SDL_Event> Events::events_;

void Events::poll (void)
{
	events_.clear();

	int eventLoop = 1;
	while (eventLoop)
	{
		SDL_Event event;
		eventLoop = SDL_PollEvent(&event);
		events_.push_back(event);
	}
}

bool Events::hasType (SDL_EventType event)
{
 	for (auto it = events_.begin(); it != events_.end(); ++it )
	{
		if (it->type == event)
			return true;
	}

	return false;
}	
