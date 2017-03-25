#ifndef PLAYER_H
#define PLAYER_H
#include "Sprite.h"
#include <iostream>
class Player :
	public Sprite
{
public:

	void update();
	void tick();
	Player(std::string filename);
	~Player();

};
#endif
