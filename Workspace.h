#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <vector>
#include "Map.h"

class Workspace
{
	public:
		static void setCurrentMap (Map & map);		
		static Map * getCurrentMap (void);		
	
	private:
		static Map* currentMap_;
};

#endif
