#pragma once
#include "../SDLInclude.h"
#include "EventHandler.h"
#include <map>
class KeyboardHandler
{
public:
	static KeyboardHandler* getInstance();
	void update();
	bool getKey(SDL_Keycode i);
private:
	std::map<SDL_Keycode, bool> keys;
	EventHandler* eh;
	KeyboardHandler();
	~KeyboardHandler();
	static KeyboardHandler* gInstance;
};

