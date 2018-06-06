#ifndef ROTATION_H
#define ROTATION_H

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>

struct Rotation : public entityx::Component<Rotation>
{
	float rot;

	Rotation(float degree)
		:rot(degree) {}
};

#endif // ROTATION_H
