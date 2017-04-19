#include "SpritesheetManager.h"
#include "WindowManager.h"
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
    IMG_Init(IMG_INIT_PNG);
    gRenderer = WindowManager::getInstance()->getRenderer();
}
SpritesheetManager::~SpritesheetManager(){
    
}
SDL_Texture* SpritesheetManager::loadSpritesheet(std::string sheetName, std::string fileName, int spriteWidth, int spriteHeight){
	SDL_Texture* sheetTex = IMG_LoadTexture(gRenderer,fileName.c_str());
	if(sheetTex==NULL){
		std::cout<<"Can't load sheet:"<<sheetName<<std::endl;
		std::cout<<IMG_GetError()<<std::endl;
		return 0;
	}
	int w,h;
	SDL_QueryTexture(sheetTex,0,0,&w,&h);
	Spritesheet sh = {sheetTex,w,h,spriteWidth,spriteHeight};
	gSpritesheets[sheetName] = sh;
	return sheetTex;
}
SDL_Rect* SpritesheetManager::getLocation(std::string sheetName, int spriteNum){
	if(gSpritesheets.count(sheetName)==0){
		std::cout<<sheetName<<" does not exist in gSpritesheets"<<std::endl;
		return 0;
	}
	Spritesheet sh = gSpritesheets[sheetName];
	
	
	int xLength = sh.sheetWidth/sh.spriteWidth;
	int yLength = sh.sheetHeight/sh.spriteHeight;
	SDL_Rect* sRect = new SDL_Rect;
	sRect->w = sh.spriteWidth;
	sRect->h = sh.spriteHeight;
	sRect->x = (spriteNum * sh.spriteWidth) % xLength;
	sRect->y = (spriteNum * sh.spriteHeight) % yLength; 
	return sRect;
}