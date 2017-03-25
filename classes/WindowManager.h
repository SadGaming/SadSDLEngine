#ifndef WINDOW_H
#define WINDOW_H
#include "../SDLInclude.h"
#include <string>
class WindowManager
{
public:
	static WindowManager* getInstance();
	SDL_Renderer * getRenderer();
	SDL_Window* createWindow(std::string name, int xpos, int ypos, int w, int h, Uint32 windowFlags, Uint32 renderFlags);
private:
	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;
	static WindowManager* gInstance;
	WindowManager();

	~WindowManager();
};
#endif
