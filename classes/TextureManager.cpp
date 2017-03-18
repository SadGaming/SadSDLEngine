#include "TextureManager.h"
#include "../SDLInclude.h"
#include <map>
#include <iostream>
TextureManager* TextureManager::gInstance = NULL;

TextureManager* TextureManager::getInstance()
{
	if (gInstance == NULL) {
		gInstance = new TextureManager();
	}
	return gInstance;
}

void TextureManager::addTexture(std::string name, SDL_Texture* mTexture) {
	
	int w, h = 0;
	SDL_QueryTexture(mTexture, NULL, NULL, &w, &h);
	gameReady t;
	t.texture = mTexture;
	t.width = w;
	t.height = h;
	
	textures[name] = t;
	
}

void TextureManager::addTexture(std::string name, std::string filename) {
	IMG_Init(IMG_INIT_PNG);
	SDL_Texture* mTexture = IMG_LoadTexture(gRenderer, filename.c_str());
	if (mTexture) {
		
		addTexture(name, mTexture);
	}
	else {
		std::cout << "Error loading img:" << IMG_GetError() << std::endl;
	}
}

gameReady TextureManager::getTexture(std::string name) {
	return textures[name];
}

TextureManager::TextureManager()
{
	gRenderer = WindowManager::getInstance()->getRenderer();
}


TextureManager::~TextureManager()
{
}
