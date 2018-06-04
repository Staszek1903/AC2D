#ifndef VELOCITY_H
#define VELOCITY_H

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>


struct Velocity : public entityx::Component<Velocity>
{
	Velocity(const sf::Vector2f & vel)
		:vel(vel) {}
	sf::Vector2f vel;
};

#endif // VELOCITY_H
