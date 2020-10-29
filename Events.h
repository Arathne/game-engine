#ifndef EVENTS_H
#define EVENTS_H

#include <vector>
#include <SDL2/SDL.h>

class Events
{
	public:
		static void poll (void);		
		static bool hasType (SDL_EventType event);		

	private:
		static std::vector<SDL_Event> events_;
};

#endif
