#include "GameplayStage.h"
#include "ResourcesManager.h"


GameplayStage::GameplayStage()
{
}

GameplayStage::~GameplayStage()
{
	release();
}

void GameplayStage::updateCamera()
{
	ResourcesManager::getInstanceRef().window.setView(ResourcesManager::getInstanceRef().camera);
}

bool GameplayStage::init()
{
    ResourcesManager::getInstanceRef().camera.reset(sf::FloatRect(0, 0, 800, 600));
    ex_ptr = std::make_unique<ECSGameplay>();

	auto &window = ResourcesManager::getInstanceRef().window;
	auto &resource = ResourcesManager::getInstanceRef();

	return true;
}

bool GameplayStage::update(float dt)
{
	dtime = dt;
	updateCamera();
    ex_ptr->update(dt);
    return true;
}

void GameplayStage::input(sf::Event & ev)
{
    if(ev.type = sf::Event::KeyPressed)
        ResourcesManager::getInstanceRef().exit_stage.set();
}

void GameplayStage::render(sf::RenderWindow & window)
{
    ex_ptr->draw();
}



void GameplayStage::release()
{
	
}
