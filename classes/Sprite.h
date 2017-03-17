#pragma once
#include <SDL.h>
#include "KeyboardHandler.h"
#include "EventHandler.h"
#include "WindowManager.h"
#include "TextureManager.h"
#include <string>
class Sprite
{
public:
	Sprite(std::string name, float x, float y, std::string filename);
	void draw();

	void update();

	SDL_Rect getCollRect();

	Uint32 timePassed();

	void tick();

	float x, y;
	int width, height;
	~Sprite();
	
	
protected:
	float speed;
	Uint32 lastUpdateCall;
	SDL_Rect dRect;
	SDL_Rect sRect;
	gameReady gTextureData;
	SDL_Texture* gTexture;
	SDL_Renderer *gRenderer;
	KeyboardHandler* kh;
	EventHandler* eh;
	
	
};

