#pragma once

#include "LibsAndDeclarations.h"
#include "GameStage.h"

class ExitStage : public GameStage
{
public:
	ExitStage();
	ExitStage(const ExitStage&) = delete;
	ExitStage& operator=(const ExitStage&) = delete;
	~ExitStage();

private:
	float timer;

public:
	virtual bool init() override;
	virtual bool update(float dt) override;
	virtual void input(sf::Event &) override;
	virtual void render(sf::RenderWindow &window) override;
//	virtual void draw(sf::RenderWindow &window) override;
	virtual void release() override;
};
