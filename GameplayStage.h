#pragma once

#include "LibsAndDeclarations.h"
#include "GameStage.h"
#include "ECSGameplay.h"
#include <memory>

class GameplayStage : public GameStage
{
public:
	GameplayStage();
	GameplayStage(const GameplayStage&) = delete;
	GameplayStage& operator=(const GameplayStage&) = delete;
	virtual ~GameplayStage();

private:
	float dtime;

	sf::View camera;
    std::unique_ptr<ECSGameplay> ex_ptr;

	void updateCamera();

public:
	virtual bool init() override;
	virtual bool update(float dt) override;
	virtual void input(sf::Event &) override;
    virtual void render(sf::RenderWindow &window) override;
	virtual void release() override;
};
