#include "WindowManager.h"
#include "../SDLInclude.h"
#include <string>
WindowManager* WindowManager::gInstance = NULL;


WindowManager* WindowManager::getInstance()
{
	if (gInstance == NULL) {
		gInstance = new WindowManager();
	}
	return gInstance;
}

SDL_Window* WindowManager::createWindow(std::string name,int xpos,int ypos,int w, int h,Uint32 windowFlags,Uint32 renderFlags)
{
	
	gWindow = SDL_CreateWindow(name.c_str(), xpos, ypos, w, h, windowFlags);
	gRenderer = SDL_CreateRenderer(gWindow, -1, renderFlags);
	return gWindow;
}

WindowManager::WindowManager()
{

}

SDL_Renderer* WindowManager::getRenderer() {
	return gRenderer;
}

WindowManager::~WindowManager()
{
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
}
