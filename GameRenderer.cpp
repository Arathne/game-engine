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

	SDL_Quit();
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

void GameRenderer::show (void)
{
	SDL_ShowWindow(window_);
}

void GameRenderer::hide (void)
{
	SDL_HideWindow(window_);
}

void GameRenderer::draw (void)
{
	SDL_SetRenderDrawColor( renderer_, 0, 0, 0, 255 );
	SDL_RenderClear( renderer_ );
	
	GameRenderer::drawMap();	

	SDL_RenderPresent( renderer_ );
}

void GameRenderer::drawMap (void)
{
	Map* currentMap = Workspace::getCurrentMap();

	if (currentMap != nullptr)
	{
		std::vector<Tile*> tiles = currentMap-> getTiles();
		
 		for (auto it = tiles.begin(); it != tiles.end(); it++ )
		{
			Tile current = **it;
			
			glm::vec2 position = current.getPosition();
			Color color = current.getColor();
			
			SDL_Rect rectangle;
			rectangle.x = position.x;
			rectangle.y = position.y;
			rectangle.w = current.getWidth();
			rectangle.h = current.getHeight();

			SDL_SetRenderDrawColor( renderer_, color.red(), color.green(), color.blue(), color.alpha() );
			SDL_RenderFillRect( renderer_, &rectangle );
		}
	}
}	
