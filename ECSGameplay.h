#pragma once

#include "LibsAndDeclarations.h"

class ECSGameplay : public entityx::EntityX
{
public:
	ECSGameplay();
	ECSGameplay(const ECSGameplay &) = delete;
	ECSGameplay& operator=(const ECSGameplay &) = delete;
	~ECSGameplay();

public:
	bool update(float dt);
	void draw(sf::RenderWindow &window);
};
