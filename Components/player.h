#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>

#define KEY sf::Keyboard::Key

struct Player : public entityx::Component<Player>
{
	KEY left, right, jump;

	float walkSpeed;
	float walkAcceleration;
	float deceleration;
	
	float jumpVelocity;

	Player(KEY left, KEY right, KEY jump)
		:left(left), right(right), jump(jump),
		walkSpeed(3),
		deceleration(1), walkAcceleration(0.5), jumpVelocity(3) {}
};

#undef KEY
#endif // !PLAYER_H
