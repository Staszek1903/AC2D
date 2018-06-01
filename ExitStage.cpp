#include "ExitStage.h"

ExitStage::ExitStage() : timer(0.f)
{
}

ExitStage::~ExitStage()
{
}

bool ExitStage::init()
{
	timer = 0.f;
	std::cout << "Exit..." << std::endl;
	return true;
}

bool ExitStage::update(float dt)
{
	timer += dt;
	if (timer >= 1.f)
	{
		timer = 0.f;
		return false;
	}

	return true;
}

void ExitStage::input(sf::Event &)
{
}

void ExitStage::render(sf::RenderWindow & window)
{
}


void ExitStage::release()
{
}
