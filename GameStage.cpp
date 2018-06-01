#include "GameStage.h"

GameStage* GameStage::active_stage = nullptr;
GameStage* GameStage::next_stage = nullptr;

GameStage::~GameStage()
{
}

bool GameStage::run(float dt, sf::RenderWindow &window)
{
	if (next_stage)
	{
		if (active_stage) active_stage->release();
		active_stage = next_stage;
		next_stage = nullptr;
		if (!active_stage->init())
		{
			active_stage->release();
			active_stage = nullptr;
			return false;
		}
	}
	if (active_stage)
	{
		if (active_stage->update(dt))
		{
			active_stage->draw(window);
		}
		else
		{
			active_stage->release();
			active_stage = nullptr;
			return false;
		}
		return true;
	}
	return false;
}

void GameStage::set()
{
	next_stage = this;
}
