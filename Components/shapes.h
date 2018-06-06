#pragma once



#ifndef SHAPES_H
#define SHAPES_H

#include <entityx\entityx.h>
#include <SFML\Graphics.hpp>
struct Circle : public entityx::Component<Circle>
{
	sf::Color color;
	float radius;

	Circle(float radius, sf::Color color)
		: radius(radius), color(color) {};
};

struct Rectangle : public entityx::Component<Rectangle>
{
	sf::Color color;
	sf::Vector2f dimensions;

	Rectangle(sf::Vector2f dimensions, sf::Color color)
		: dimensions(dimensions), color(color) {}
};


#endif // !SHAPES_H
