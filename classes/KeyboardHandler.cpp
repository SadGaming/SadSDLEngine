#include "KeyboardHandler.h"
#include "EventHandler.h"
#include "../SDLInclude.h"
KeyboardHandler* KeyboardHandler::gInstance = NULL;

KeyboardHandler * KeyboardHandler::getInstance()
{
	if (gInstance == NULL) {
		gInstance = new KeyboardHandler();
	}
	return gInstance;

}

KeyboardHandler::KeyboardHandler()
{
	eh = EventHandler::getInstance();
}


KeyboardHandler::~KeyboardHandler()
{
}

void KeyboardHandler::update() {
	
	std::vector<SDL_Event> keydowns, keyups;
	if (eh->containsEvent(SDL_KEYDOWN) | eh->containsEvent(SDL_KEYUP)) {
		keydowns = eh->getEvents(SDL_KEYDOWN);
		keyups = eh->getEvents(SDL_KEYUP);
		for (Uint32 i = 0; i < keydowns.size(); i++){
			SDL_Event e = keydowns[i];
			keys[e.key.keysym.sym] = true;
		}
		for (Uint32 i = 0; i < keyups.size(); i++) {
			SDL_Event e = keyups[i];
			keys[e.key.keysym.sym] = false;
		}
	}
	
}
bool KeyboardHandler::getKey(SDL_Keycode i) {
	return keys[i];
}
