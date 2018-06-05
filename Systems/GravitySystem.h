#pragma once

#ifndef GRAVITYSYSTEM_H
#define GRAVITYSYSTEM_H

#include <entityx/entityx.h>
#include "Components/velocity.h"
#include "Components\gravity.h"

class GravitySystem : public entityx::System<GravitySystem>
{
public:
	GravitySystem();
	void update(entityx::EntityManager & en, entityx::EventManager & ev, double dt);
};

#endif // !GRAVITYSYSTEM_H
