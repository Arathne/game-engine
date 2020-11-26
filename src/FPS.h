#ifndef FPS_H
#define FPS_H

#include <SDL2/SDL.h>
#include <iostream>

class FPS
{
	public:
		static void check (void);
		static void setMaxFramerate (unsigned int framerate);
		static unsigned int getFramesPerSecond (void);

	private:
		static unsigned int framerate_;
		static unsigned int fps_;
		static unsigned int frameCounter_;
		static unsigned int lastFrameTime_;
		static unsigned int lastSecondTime_;
};

#endif
