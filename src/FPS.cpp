#include "FPS.h"

unsigned int FPS::framerate_ = 120;
unsigned int FPS::fps_ = 0;
unsigned int FPS::frameCounter_ = 0;
unsigned int FPS::lastFrameTime_ = 0;
unsigned int FPS::lastSecondTime_ = 0;

void FPS::check (void)
{
	unsigned int timePerFrame = 1000 / (framerate_/2);
	
	unsigned int currentTime = SDL_GetTicks();
	unsigned int frameTimeElapsed = currentTime - lastFrameTime_;
	unsigned int secondTimeElapsed = currentTime - lastSecondTime_;
	
	if (secondTimeElapsed > 1000)
	{
		lastSecondTime_ = currentTime;
		fps_ = frameCounter_;
		frameCounter_ = 0;
		std::cout << "FPS: " << fps_ << std::endl;
	}
	else
		frameCounter_++;
	
	if (frameTimeElapsed <= timePerFrame)
		SDL_Delay( (int) ((timePerFrame - frameTimeElapsed) * 0.8) );
	
	lastFrameTime_ = currentTime;
}

void FPS::setMaxFramerate (unsigned int framerate)
{
	framerate_ = framerate;
}

unsigned int FPS::getFramesPerSecond (void)
{
	return fps_;
}
