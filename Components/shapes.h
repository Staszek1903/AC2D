#pragma once

#ifndef SHAPES_H
#define SHAPES_H

#include <entityx\entityx.h>
#include <SFML\Graphics.hpp>
struct CircleShape : public entityx::Component<CircleShape>
{
	sf::Color color;
	sf::Texture *texture;
	float radius;
	unsigned short pointCount;

	CircleShape(float radius, sf::Color color , sf::Texture *texture=nullptr, unsigned short pointCount = 50)
		: radius(radius), color(color), texture(texture), pointCount(pointCount) {};
};

struct RectangleShape : public entityx::Component<RectangleShape>
{
	sf::Color color;
	sf::Vector2f dimensions;
	sf::Texture *texture;

	RectangleShape(sf::Vector2f dimensions, sf::Color color, sf::Texture *texture = nullptr)
		: dimensions(dimensions), color(color), texture(texture) {}
};

struct Shape : public entityx::Component<Shape>
{
	sf::VertexArray v;
	sf::Texture texture;

	Shape(sf::VertexArray & v, sf::Texture texture)
		:v(v), texture(texture) {}
};

struct SpriteShape : public entityx::Component<SpriteShape>
{
	sf::Texture texture;

	SpriteShape(sf::Texture texture)
		: texture(texture) {}
};

#endif // !SHAPES_H
