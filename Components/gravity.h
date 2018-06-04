#pragma once

#ifndef GRAVITY_H
#define GRAVITY_H

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>

struct Gravity : public entityx::Component<Gravity>
{
	float gravity_strength;

	Gravity(float gravity_strength)
		:gravity_strength(gravity_strength) {}
};

#endif // !GRAVITY_H
