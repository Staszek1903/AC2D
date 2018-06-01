#pragma once

#include "LibsAndDeclarations.h"

class DrawSystem : public entityx::System<DrawSystem>
{
public:
	DrawSystem() = default;
	DrawSystem(const DrawSystem&) = delete;
	DrawSystem& operator=(const DrawSystem&) = delete;

public:
	void update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt) override;
};
