#ifndef STATIC_SPRITE_H
#define STATIC_SPRITE_H

#include "SpriteBase.h"

class StaticSprite : public SpriteBase
{
	public:
		StaticSprite (void);
		~StaticSprite (void);
		
		int getType (void) const;
		void update (void);
};

#endif
