#ifndef EVENTS_H
#define EVENTS_H

#include <vector>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class Events
{
	public:
		static void poll (void);		
		static bool hasType (SDL_EventType event);		
		static bool isKeyPressed (SDL_Scancode code);
		static void getMousePosition (int* x, int* y);

	private:
		static std::vector<SDL_Event> events_;
		static const Uint8* keyboard_;
};

#endif
