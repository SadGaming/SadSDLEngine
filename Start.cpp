#include <iostream>
#include <SDL_image.h>
#include <SDL.h>
#include "classes/EventHandler.h"
#include "classes/KeyboardHandler.h"
#include "classes/WindowManager.h"
#include "classes/Sprite.h"
#include "classes/Player.h"

const int FPS = 60;
const int TPF = 1000 / FPS;

int main(int argc, char** argv) {
	SDL_Init(SDL_INIT_EVERYTHING);
	WindowManager* wm = WindowManager::getInstance();
	SDL_Window *window = wm->createWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0, 0);
	
	SDL_Renderer *gRenderer = wm->getRenderer();
	IMG_Init(IMG_INIT_PNG);
	SDL_Texture *gTexture = IMG_LoadTexture(gRenderer, "images/background.png");
	if (gTexture == NULL) {
		std::cout << IMG_GetError()<<std::endl;
	}
	bool gameRunning = true;
	

	Player player = Player("images/player.png");
	KeyboardHandler* kh = KeyboardHandler::getInstance();
	EventHandler* eh = EventHandler::getInstance();
	Uint32 startTime = SDL_GetTicks();
	while (gameRunning) {
		int startFrame = SDL_GetTicks();
		eh->poll();
		if (eh->containsEvent(SDL_QUIT)) {
			gameRunning = false;
		}
		kh->update();
		
		
		SDL_RenderClear(gRenderer);
		
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
		player.tick();
		SDL_RenderPresent(gRenderer);
		
		Uint32 endFrame = SDL_GetTicks();
		Uint32 frameTime = endFrame - startFrame;
		
		if (frameTime < TPF) {
			SDL_Delay(TPF - (endFrame - startFrame));
		}
		
	}
	SDL_Quit();
	return 0;
	
}
