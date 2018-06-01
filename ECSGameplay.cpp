#include "ECSGameplay.h"
#include "ResourcesManager.h"
#include "DrawSystem.h"

ECSGameplay::ECSGameplay()
{
	systems.add<DrawSystem>();

	systems.configure();
}

ECSGameplay::~ECSGameplay()
{
}

bool ECSGameplay::update(float dt)
{
	return true;
}

void ECSGameplay::draw(sf::RenderWindow &window)
{
	systems.update<DrawSystem>(0.f);
}
