#include "Scene.h"

Scene::Scene (void):
	visible_ (false),
	color_ (Color::make(255,192,203,255))
{}

Scene::Scene (Color color):
	visible_ (false),
	color_ (color)
{}

Scene::~Scene (void) {}

void Scene::show (void)
{
	visible_ = true;
}

void Scene::hide (void)
{
	visible_ = false;
}

bool Scene::isVisible (void) const
{
	return visible_;
}

Color Scene::getColor (void) const
{
	return color_;
}
