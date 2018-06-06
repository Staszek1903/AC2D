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
	
	/*Test map objects*/
	auto en = ex_ptr->entities.create();
	en.assign<Player>(sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up);
	en.assign<Position>(sf::Vector2f(400, 50));
	en.assign<Gravity>(10.0);
	en.assign<Velocity>(sf::Vector2f(0, 0));
	en.assign<Rotation>(0);
	en.assign<Circle>(30, sf::Color::Red);

	en = ex_ptr->entities.create();
	en.assign<Position>(sf::Vector2f(200, 100));
	en.assign<Gravity>(0.1);
	en.assign<Velocity>(sf::Vector2f(0, 0));
	en.assign<Rotation>(0);
	en.assign<Rectangle>(sf::Vector2f(50, 20), sf::Color::Blue);
	/*-Test map objects-*/

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
    if(ev.type == sf::Event::KeyPressed 
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        //std::cout<<"pressed"<<std::endl;
        ResourcesManager::getInstanceRef().exit_stage.set();
    }
}

void GameplayStage::render(sf::RenderWindow & window)
{
    window.clear(sf::Color::Green);
    ex_ptr->draw();
}



void GameplayStage::release()
{
	
}
