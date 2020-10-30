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
	
	IMG_Init(IMG_INIT_PNG);
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
	GameRenderer::checkTextures();

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
			
			int textureIndex = GameRenderer::getTextureIndex(current.getTextureId());
			if (textureIndex < 0)
				SDL_RenderFillRect( renderer_, &rectangle );
			else
				SDL_RenderCopy( renderer_, loadedTextures_.at(textureIndex), nullptr, &rectangle );
		}
	}
}

void GameRenderer::checkTextures (void)
{
	std::vector<Texture*> workspaceTextures = Workspace::getTextures();
	for (auto it = workspaceTextures.begin(); it != workspaceTextures.end(); it++)
	{
		Texture current = **it;
		if (GameRenderer::isTextureInRenderer(current) == false)
			GameRenderer::loadTexture(current);
	}
	
	int index = 0;
	for (auto it = textures_.begin(); it != textures_.end(); it++)
	{
		Texture current = **it;
		if (GameRenderer::isTextureInWorkspace(current) == false)
		{
			std::cout << "destroying texture :: " << current.getId() << std::endl;
			
			SDL_DestroyTexture( loadedTextures_.at(index) );
			 
			loadedTextures_.erase( loadedTextures_.begin() + index );
			
			textures_.erase( it-- );
			std::cout << "successfully destroyed" << std::endl; 
			index--;
		}
		index++;
	}
}

void GameRenderer::loadTexture (Texture & texture)
{
	if (isTextureInRenderer(texture) == false)
	{
		SDL_Surface* surface = IMG_Load(texture.getPath());
		SDL_Texture* newLoadedTexture = SDL_CreateTextureFromSurface( renderer_, surface );
		
		loadedTextures_.push_back(newLoadedTexture);
		textures_.push_back(&texture);
	
		std::cout << "loaded texture :: " << texture.getPath() << "::" << texture.getId() << std::endl;

		SDL_FreeSurface(surface);
	}
}

bool GameRenderer::isTextureInWorkspace (Texture & texture) const
{
	std::vector<Texture*> workspaceTextures = Workspace::getTextures();
	for (auto it = workspaceTextures.begin(); it != workspaceTextures.end(); it++)
	{
		Texture current = **it;
		if (current == texture)
			return true;
	}

	return false;
}

bool GameRenderer::isTextureInRenderer (Texture & texture) const
{
	for (auto it = textures_.begin(); it != textures_.end(); it++)
	{
		Texture current = **it;
		if (current == texture)
			return true;
	}
	
	return false;
}

int GameRenderer::getTextureIndex (unsigned int id) const
{
	int index = 0;
	for (auto it = textures_.begin(); it != textures_.end(); it++)
	{
		Texture current = **it;
		if (current.getId() == id)
			return index;
		
		index++;
	}
	
	return -1;
}
