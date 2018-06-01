#pragma once

#include "LibsAndDeclarations.h"

class GameStage
{
public:
	GameStage() = default;
	GameStage(const GameStage&) = delete;
	GameStage& operator=(const GameStage&) = delete;
	virtual ~GameStage();

private:
	static GameStage *active_stage;
	static GameStage *next_stage;

public:
	static bool run(float dt, sf::RenderWindow &window);
	static GameStage* activeStage() { return active_stage; };

private:
public:
	void set();
	virtual bool init() = 0;
	virtual bool update(float dt) = 0;
	virtual void draw(sf::RenderWindow &window) = 0;
	virtual void release() = 0;
};
