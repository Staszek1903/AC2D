#include "ECSGameplay.h"
#include "ResourcesManager.h"

ECSGameplay::ECSGameplay()
{
    systems.add<RenderSystem>(ResourcesManager::getInstanceRef().window);
    systems.add<MovementSystem>();
	systems.configure();
}

ECSGameplay::~ECSGameplay()
{
}

bool ECSGameplay::update(float dt)
{
    systems.update<MovementSystem>(dt);
	return true;
}

void ECSGameplay::draw()
{
    systems.update<RenderSystem>(0.f);
}
