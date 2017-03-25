#ifndef SPRITE_H
#define SPRITE_H
#include <string>
#include "KeyboardHandler.h"
#include "EventHandler.h"
#include "WindowManager.h"
#include "TextureManager.h"
#include "../SDLInclude.h"

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
	SDL_Rect dRect;
	SDL_Rect sRect;
protected:
	float speed;
	Uint32 lastUpdateCall;
	gameReady gTextureData;
	SDL_Texture* gTexture;
	SDL_Renderer *gRenderer;
	KeyboardHandler* kh;
	EventHandler* eh;
};
#endif
