#pragma once

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>

/********Example********

struct Position : public entityx::Component<Position>
{
Position(const sf::Vector2f & pos)
:pos(pos), prevPos(pos) {}
sf::Vector2f pos;
sf::Vector2f prevPos;
};

struct Rotation : public entityx::Component<Rotation>
{
Rotation(float degree)
:degree(degree) {}	
float degree;
};

*/