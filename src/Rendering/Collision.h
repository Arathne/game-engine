#ifndef COLLISION_H
#define COLLISION_H

#include <vector>
#include <glm/glm.hpp>

#include "../Sprite/Sprite.h"

class Collision
{
	public:
		static void check (std::vector<Sprite*> & sprites);

	private:
		static void checkSprite (Sprite & sprite, std::vector<Sprite*> & sprites);
		static bool didCollide (Sprite & sprite1, Sprite & sprite2);
		static void bounce (Sprite & sprite);
};

#endif
