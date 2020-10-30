#include "Workspace.h"

Map* Workspace::currentMap_ = nullptr;

void Workspace::setCurrentMap (Map & map)
{
	currentMap_ = &map;
}


Map * Workspace::getCurrentMap (void)
{
	return currentMap_;
}		
