#ifndef POSITION_H
#define POSITION_H

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>


struct Position : public entityx::Component<Position>
{
	Position(const sf::Vector2f & pos)
		:pos(pos) {}
	sf::Vector2f pos;
};

#endif // POSITION_H
