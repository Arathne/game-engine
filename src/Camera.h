#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <iostream>

enum DIRECTION {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Camera
{
	public:
		Camera (void);
		Camera (float x, float y, int radius);
		~Camera (void);

		void move (DIRECTION direction);

		void setPosition (float x, float y);
		void setRadius (int radius);
		void setSpeed (int speed);
		
		int getRadius (void) const;
		int getSpeed (void) const;
		glm::vec2 getPosition (void) const;
		glm::mat3 getTransform (void) const;
	

	private:
		glm::mat3 transform_;
		int speed_;
		int radius_;
};

#endif
