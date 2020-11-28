#ifndef EVENTS_H
#define EVENTS_H

#include <vector>
#include <SDL2/SDL.h>

class Events
{
	public:
		static void poll (void);		
		static bool hasType (SDL_EventType event);		
		static bool isKeyPressed (SDL_Scancode code);

	private:
		static std::vector<SDL_Event> events_;
		static const Uint8* keyboard_;
};

#endif
