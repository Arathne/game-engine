#include "GameRenderer.h"

/* CONSTRUCTORS || DESTRUCTOR */

GameRenderer::GameRenderer (void) 
{
	init(800, 800, "Game");
}

GameRenderer::GameRenderer (unsigned int w, unsigned int h, const char* windowTitle)
{
	init(w, h, windowTitle);
}


/* destroys window and textures loaded in gpu
*/
GameRenderer::~GameRenderer (void)
{
	if (renderer_ != nullptr)
		SDL_DestroyRenderer(renderer_);
	
	if (window_ != nullptr)
		SDL_DestroyWindow(window_);
	
	int index = 0;
	for (auto it = loadedTextures_.begin(); it != loadedTextures_.end(); it++)
	{
			SDL_Texture* current = *it;			
			Texture textureObj = *textures_.at(index);

			std::cout << "destroyed texture :: " << textureObj.getId() << std::endl;
			SDL_DestroyTexture( current );
			index++;	 
	}
	
	SDL_Quit();
}


/* initializes renderer and crashes program if failed
*/
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


/* show window
*/
void GameRenderer::show (void)
{
	SDL_ShowWindow(window_);
}


/* hide window
*/
void GameRenderer::hide (void)
{
	SDL_HideWindow(window_);
}


/* draws everything in game
*/
void GameRenderer::draw (void)
{
	GameRenderer::checkTextures();	

	SDL_SetRenderDrawColor( renderer_, 0, 0, 0, 255 );
	SDL_RenderClear( renderer_ );
	
	GameRenderer::drawMap();
	GameRenderer::drawSprites();

	SDL_RenderPresent( renderer_ );
	Workspace::tick();
	
	FPS::check();
}


/* draws a single square
*/
void GameRenderer::drawRectangle (float x, float y, int w, int h, Color color, unsigned int textureId) const
{
	Camera camera = Workspace::getCamera();
	glm::vec3 position = camera.getTransform() * glm::vec3(x, y, 1.0f);
	
	SDL_Rect rectangle;
	rectangle.x = position.x;
	rectangle.y = position.y;
	rectangle.w = w;
	rectangle.h = h;
			
	SDL_SetRenderDrawColor( renderer_, color.red(), color.green(), color.blue(), color.alpha() );
			
	int textureIndex = GameRenderer::getTextureIndex(textureId);
	if (textureIndex < 0)
		SDL_RenderFillRect( renderer_, &rectangle );
	else
		SDL_RenderCopy( renderer_, loadedTextures_.at(textureIndex), nullptr, &rectangle );
}


/* gets all tiles in map and draws them
*/
void GameRenderer::drawMap (void)
{
	Map* currentMap = Workspace::getCurrentMap();

	if (currentMap != nullptr)
	{
		std::vector<Tile*> tiles = currentMap-> getTiles();
		Camera camera = Workspace::getCamera();

 		for (auto it = tiles.begin(); it != tiles.end(); it++ )
		{
			Tile current = **it;
			glm::vec2 position = current.getPosition();
			GameRenderer::drawRectangle((float)position.x, (float)position.y, current.getWidth(), current.getHeight(), current.getColor(), current.getTextureId());
		}
	}
}

void GameRenderer::drawSprites (void) const
{
	std::vector<Sprite*> sprites = Workspace::getSprites();
	
	for (auto it = sprites.begin(); it != sprites.end(); it++)
	{
		if ((**it).isVisible())
		{
			Rectangle frame = (**it).getFrame();
		
			glm::vec2 position = (**it).getPosition();
		
			GameRenderer::drawRectangle((float)position.x, (float)position.y, frame.getWidth(), frame.getHeight(), frame.getColor(), frame.getTextureId());
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
	
		std::cout << "loaded texture :: " << texture.getPath() << " :: " << texture.getId() << std::endl;

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
