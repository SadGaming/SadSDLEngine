#ifndef SPRITESHEET_H
#define SPRITESHEET_H
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "../SDLInclude.h"
struct Spritesheet {
	SDL_Texture* tex;
	int sheetWidth;
	int sheetHeight;
	int spriteWidth;
	int spriteHeight;
};
class SpritesheetManager 
{
public:
	static SpritesheetManager* getInstance();
	SDL_Texture* loadSpritesheet(std::string sheetName, std::string fileName, int spriteWidth, int spriteHeight);
	SDL_Rect* getLocation(std::string sheetName, int spriteNum);
private:
	SDL_Renderer* gRenderer;
	std::map< std::string, Spritesheet > gSpritesheets;
	static SpritesheetManager* gInstance;
	SpritesheetManager();
	~SpritesheetManager();
};
#endif 