#include "Player.h"
#include <iostream>


Player::Player(std::string filename) : Sprite("Player", 0, 0, filename)
{
	speed = 200;

}

void Player::update() {
	
	float ticks = timePassed() / 1000.0f;
	if (kh->getKey(SDLK_w)) {
		y -= (speed*ticks);
	}
	if (kh->getKey(SDLK_a)) {
		x -= (speed*ticks);
	}
	if (kh->getKey(SDLK_s)) {
		y += (speed*ticks);
	}
	if (kh->getKey(SDLK_d)) {
		x += (speed*ticks);
	}
	speed *=1.000002;
	Sprite::update();
}
void Player::tick() {
	update();
	draw();
}


Player::~Player()
{
}
