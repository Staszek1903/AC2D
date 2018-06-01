#include "DrawSystem.h"
#include "ResourcesManager.h"
#include "Body.h"

void DrawSystem::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt)
{
	auto &window = ResourcesManager::getInstanceRef().window;
	entityx::ComponentHandle<Body> body;
	for (entityx::Entity e : es.entities_with_components(body))
	{
		window.draw(body->cirle);
	}
}
