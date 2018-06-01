#pragma once

#include "LibsAndDeclarations.h"
#include "GameStage.h"
#include "ECSGameplay.h"

class GameplayStage : public GameStage
{
public:
	GameplayStage();
	GameplayStage(const GameplayStage&) = delete;
	GameplayStage& operator=(const GameplayStage&) = delete;
	virtual ~GameplayStage();

private:
	sf::View camera;
	std::unique_ptr<ECSGameplay> ecs_gameplay_ptr;

	void updateCamera();

public:
	virtual bool init() override;
	virtual bool update(float dt) override;
	virtual void draw(sf::RenderWindow &window) override;
	virtual void release() override;
};
