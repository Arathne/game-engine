#include "GameRenderer.h"

GameRenderer::GameRenderer (void) 
{
	init(800, 800, "Game");
}

GameRenderer::GameRenderer (unsigned int w, unsigned int h, const char* windowTitle)
{
	init(w, h, windowTitle);
}

GameRenderer::~GameRenderer (void) 
{
	if (renderer_ != nullptr)
		SDL_DestroyRenderer(renderer_);
	
	if (window_ != nullptr)
		SDL_DestroyWindow(window_);
}

void GameRenderer::init (unsigned int w, unsigned int h, const char* windowTitle)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw std::runtime_error("Failed to initialize sdl2");

	window_ = SDL_CreateWindow( windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_HIDDEN );

	if (window_ == nullptr)
		throw std::runtime_error("Failed to initialize window");

	renderer_ = SDL_CreateRenderer( window_, -1, SDL_RENDERER_PRESENTVSYNC );

	if (renderer_ == nullptr)
		throw std::runtime_error("Failed to initialize renderer");
}

void GameRenderer::start (void)
{
	
}
