#include "Events.h"

std::vector<SDL_Event> Events::events_;
bool Events::keyboard_[130];

void Events::poll (void)
{
	events_.clear();

	int eventLoop = 1;
	while (eventLoop)
	{
		SDL_Event event;
		eventLoop = SDL_PollEvent(&event);
		events_.push_back(event);
	
		if (event.type == SDL_KEYUP) {
			keyboard_[event.key.keysym.sym] = false;
		}
		else if (event.type == SDL_KEYDOWN) {
			keyboard_[event.key.keysym.sym] = true;
		}
	}
}

bool Events::hasType (SDL_EventType event)
{
 	for (auto it = events_.begin(); it != events_.end(); it++ )
	{
		if (it->type == event)
			return true;
	
	}

	return false;
}

bool Events::isKeyPressed (int ascii)
{
	if (ascii >= 0 && ascii < 130)
		return keyboard_[ascii];

	return false;
}
