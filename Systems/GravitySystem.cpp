#include "GravitySystem.h"

GravitySystem::GravitySystem()
{}

void GravitySystem::update(entityx::EntityManager & en, entityx::EventManager & ev, double dt)
{
	Velocity::Handle vel;
	Gravity::Handle gravity;
	// Collision::Handle coll;

	for (auto entity : en.entities_with_components(vel, gravity))
	{
		// if(!coll->collision.collidesFloor)
		{
			vel->vel.y += gravity->gravity_strength * dt;
		}
	}

}
