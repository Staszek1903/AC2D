#pragma once

#ifndef VERTEX_DATA_H
#define VERTEX_DATA_H

#include <SFML\Graphics.hpp>

static sf::Vector2f quad_vertex[] =
{
	{-40 ,-10 },
	{ 40 ,-10 },
	{ 60 , 40 },
	{-60 , 40 }
};

static sf::Vector2f quad_texture[] =
{
	{ 0, 0 },
	{ 400 ,0 },
	{ 400 ,400 },
	{ 0,  400 }
};

#endif // !VERTEX_DATA_H
