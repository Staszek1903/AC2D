#pragma once

#include "LibsAndDeclarations.h"
#include "Components\shapes.h"
#include "Components\position.h"
#include "Components\rotation.h"

class RenderSystem : public entityx::System<RenderSystem>
{
	sf::RenderWindow &win;
	sf::Texture engineTexture;

public:
	RenderSystem(sf::RenderWindow &window);

	void update(entityx::EntityManager & en, entityx::EventManager & ev, double dt);
	~RenderSystem();
};
