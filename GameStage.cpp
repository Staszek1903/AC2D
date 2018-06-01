#include "GameStage.h"

GameStage* GameStage::active_stage = nullptr;
GameStage* GameStage::next_stage = nullptr;

GameStage::~GameStage()
{
}

bool GameStage::stage_switch()
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
	return true;
}

void GameStage::stage_input(sf::Event & event)
{
	if (active_stage)
		active_stage->input(event);
}

bool GameStage::stage_update(float dt)
{
	if (active_stage)
	{
		if (!active_stage->update(dt))
		{
			active_stage->release();
			active_stage = nullptr;
			return false;
		}

		return true;
	}

	return false;
}

void GameStage::stage_render(sf::RenderWindow &window)
{
	if (active_stage)
		active_stage->render(window);
}

void GameStage::set()
{
	next_stage = this;
}
