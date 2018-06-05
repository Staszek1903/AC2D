#include "ECSGameplay.h"
#include "ResourcesManager.h"

ECSGameplay::ECSGameplay()
{
    systems.add<RenderSystem>(ResourcesManager::getInstanceRef().window);
    systems.add<MovementSystem>();
	systems.add<PlayerSystem>();
	systems.add<GravitySystem>();
	systems.configure();
}

ECSGameplay::~ECSGameplay()
{
}

bool ECSGameplay::update(float dt)
{
    systems.update<MovementSystem>(dt);
	systems.update<PlayerSystem>(dt);
	systems.update<GravitySystem>(dt);
	return true;
}

void ECSGameplay::draw()
{
    systems.update<RenderSystem>(0.f);
}
