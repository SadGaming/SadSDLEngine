#include "SpritesheetManager.h"
#include "../SDLInclude.h"

SpritesheetManager* SpritesheetManager::gInstance = NULL;

SpritesheetManager* SpritesheetManager::getInstance()
{
	if (gInstance == NULL) {
		gInstance = new SpritesheetManager();
	}
	return gInstance;
}

SpritesheetManager::SpritesheetManager(){
    
}
SpritesheetManager::~SpritesheetManager(){
    
}