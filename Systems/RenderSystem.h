#pragma once

#include "LibsAndDeclarations.h"

class RenderSystem : public entityx::System<RenderSystem>
{
	sf::RenderWindow &win;
	sf::Texture engineTexture;

public:
	RenderSystem(sf::RenderWindow &window);

	void update(entityx::EntityManager & en, entityx::EventManager & ev, double dt);
	~RenderSystem();
};
