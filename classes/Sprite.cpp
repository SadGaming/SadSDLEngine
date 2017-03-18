#include "Sprite.h"
#include "TextureManager.h"
#include "../SDLInclude.h"
#include <string>
#include <cmath>
#include <iostream>

Sprite::Sprite(std::string name, float xPos, float yPos, std::string filename)
{
	TextureManager::getInstance()->addTexture(name, filename);
	gTextureData = TextureManager::getInstance()->getTexture(name);
	gRenderer = WindowManager::getInstance()->getRenderer();
	gTexture = gTextureData.texture;
	width = gTextureData.width;
	height = gTextureData.height;
	x = xPos;
	y = yPos;
	kh = KeyboardHandler::getInstance();
	eh = EventHandler::getInstance();
	sRect.x = sRect.y = 0;
	sRect.w = width;
	sRect.h = height;
	dRect.x = (int) x;
	dRect.y = (int) y;
	dRect.w = width;
	dRect.h = height;
	
	speed = 20;
}

void Sprite::draw() {
	
	
	SDL_RenderCopy(gRenderer, gTexture, &sRect,&dRect);
}
void Sprite::update() {
	dRect.x = (int) std::floor(x);
	dRect.y = (int) std::floor(y);
	dRect.w = width;
	dRect.h = height;
	

}
SDL_Rect Sprite::getCollRect()
{
	return dRect;
}
Uint32 Sprite::timePassed() {
	Uint32 ticks = SDL_GetTicks() - lastUpdateCall;
	lastUpdateCall = SDL_GetTicks();
	return ticks;
}
void Sprite::tick() {
	update();
	draw();
}
Sprite::~Sprite()
{
	SDL_DestroyTexture(gTexture);
}

