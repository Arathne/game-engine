#ifndef EVENTS_H
#define EVENTS_H

#include <vector>
#include <SDL2/SDL.h>
#include <iostream>

class Events
{
	public:
		static void poll (void);		
		static bool hasType (SDL_EventType event);		
		static bool isKeyPressed (int ascii);

	private:
		static std::vector<SDL_Event> events_;
		static bool keyboard_[130];
};

#endif
