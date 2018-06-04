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

	Player(KEY left, KEY right, KEY jump, float walkSpeed)
		:left(left), right(right), jump(jump),
		walkSpeed(walkSpeed),
		deceleration(1000), walkAcceleration(500), jumpVelocity(200) {}
};

#endif // !PLAYER_H
