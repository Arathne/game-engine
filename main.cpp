#include <iostream>

#include "GameRenderer.h"
#include "Events.h"
#include "Color.h"

int main()
{
	GameRenderer renderer(500, 500, "Hello World");
	//renderer.show();

	bool run = false;
	while (run)
	{
		Events::poll();
		if (Events::hasType(SDL_QUIT))
			run = false;		

		renderer.draw();
	}

	Color color2(100, 214, 20, 0);
	Color color1;
	color1 = Color::make(1,2,3,4);
	
	std::cout << "COLOR 1: " << color1.red() << " " << color1.green() << " " << color1.blue() << std::endl;
	std::cout << "COLOR 2: " << color2.red() << " " << color2.green() << " " << color2.blue() << std::endl;
}
