#include "Collision.h"

void Collision::check (std::vector<Sprite*> & sprites)
{
	for (auto it = sprites.begin(); it != sprites.end(); it++ )
	{
		Sprite* currentSprite = (*it);
		Collision::checkSprite (*currentSprite, sprites);
	}
}

void Collision::checkSprite (Sprite & sprite, std::vector<Sprite*> & sprites)
{
	for (auto it = sprites.begin(); it != sprites.end(); it++ )
	{
		Sprite* currentSprite = (*it);
		
		if (sprite != *currentSprite)
		{
			if (Collision::didCollide( sprite, *currentSprite ))
			{
				glm::vec2 sprite1_position = sprite.getPosition();
				glm::vec2 sprite2_position = (*currentSprite).getPosition();
				glm::vec2 offset = sprite.getDirection() * -1.0f;		
				
				sprite.setPosition(sprite1_position + offset);
				sprite.setVelocity(sprite.getVelocity() * -1.0f);
			}
		}
	}

	Collision::bounce(sprite);
}

bool Collision::didCollide (Sprite & sprite1, Sprite & sprite2)
{
	bool collided = false;

	if (sprite1 != sprite2)
	{
		glm::vec2 sprite1_position = sprite1.getPosition();
		glm::vec2 sprite2_position = sprite2.getPosition();
			
		glm::vec2 sprite1_bounding = sprite1_position + sprite1.getSize();
		glm::vec2 sprite2_bounding = sprite2_position + sprite2.getSize();

		if (sprite1_position.x < sprite2_bounding.x)
			if (sprite1_bounding.x > sprite2_position.x)
				if (sprite1_position.y < sprite2_bounding.y )
					if (sprite1_bounding.y > sprite2_position.y)
						collided = true;
	}

	return collided;
}

void Collision::bounce (Sprite & sprite)
{
	glm::vec2 position = sprite.getPosition();
	glm::vec2 size = sprite.getSize();
	glm::vec2 velocity = sprite.getVelocity();

	if (position.x + size.x > 1280)
	{
		position.x = 1280 - size.x;
		velocity.x = velocity.x * -1.0f;
	}
	else if (position.x < 0)
	{
		position.x = 0;
		velocity.x = velocity.x * -1.0f;
	}
	
	if (position.y + size.y > 720)
	{
		position.y = 720 - size.y;
		velocity.y = velocity.y * -1.0f;
	}
	else if (position.y < 0)
	{
		position.y = 0;
		velocity.y = velocity.y * -1.0f;
	}
		
	sprite.setVelocity(velocity);
	sprite.setPosition(position);
}
