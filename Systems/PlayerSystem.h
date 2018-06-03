#pragma once

#ifndef PLAYERSYSTEM_H
#define PLAYERSYSTEM_H


#include <entityx/entityx.h>

class PlayerSystem : public entityx::System<PlayerSystem>
{
public:
	PlayerSystem();
	void update(entityx::EntityManager & en, entityx::EventManager & ev, double dt);
};


#endif // PLAYERSYSTEM_h