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
	static bool stage_switch();
	static void stage_input(sf::Event &event);
	static bool stage_update(float dt);
	static void stage_render(sf::RenderWindow &window);
	static GameStage* activeStage() { return active_stage; }

private:
public:
	void set();
	virtual bool init() = 0;
	virtual void input(sf::Event &) = 0;
	virtual bool update(float dt) = 0;
	virtual void render(sf::RenderWindow &window) = 0;
	virtual void release() = 0;
};
