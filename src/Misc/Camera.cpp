#include "Camera.h"

#define DEFAULT_SPEED 3
#define DEFAULT_RADIUS 3

Camera::Camera (void):
	transform_(glm::mat3(1.0f)),
	speed_(DEFAULT_SPEED),
	radius_(DEFAULT_RADIUS)
{}

Camera::Camera (float x, float y, int radius):
	transform_( glm::translate(glm::mat3(1.0f), glm::vec2(x, y)) ),
	speed_(DEFAULT_SPEED),
	radius_(radius)
{}

Camera::~Camera (void) {}

void Camera::setPosition (float x, float y) 
{
	transform_ = glm::translate(transform_, glm::vec2(x, y));
}

void Camera::setRadius (int radius) 
{
	radius_ = radius;
}

void Camera::setSpeed (int speed) 
{
	speed_ = speed;
}

int Camera::getSpeed (void) const 
{
	return speed_;
}

int Camera::getRadius (void) const 
{
	return radius_;
}

glm::vec2 Camera::getPosition (void) const
{
	glm::vec3 row = transform_[2];
	return glm::vec2(row.x, row.y);
}

glm::mat3 Camera::getTransform (void) const
{
	return transform_;
}

void Camera::move(DIRECTION direction)
{
	glm::vec2 move;
	
	
	if (direction == UP)
		glm::vec2(0, -speed_);	
	if (direction == DOWN)
		glm::vec2(0, speed_);	
	if (direction == LEFT)
		glm::vec2(-speed_, 0);	
	if (direction == RIGHT)
		glm::vec2(speed_, 0);	
	
	transform_ = glm::translate(transform_, move);
}
