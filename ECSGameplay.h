#pragma once

#include "LibsAndDeclarations.h"
#include "Systems/RenderSystem.h"
#include "Systems/movementsystem.h"
#include "Systems\GravitySystem.h"
#include "Systems\PlayerSystem.h"

class ECSGameplay : public entityx::EntityX
{
public:
	ECSGameplay();
	ECSGameplay(const ECSGameplay &) = delete;
	ECSGameplay& operator=(const ECSGameplay &) = delete;
	~ECSGameplay();

public:
	bool update(float dt);
    void draw();
};
