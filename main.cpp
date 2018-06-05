#include "LibsAndDeclarations.h"

#include "ResourcesManager.h"
#include "sstream"

void input();
bool update();
void render();

std::shared_ptr<sf::Event> foo;

int main()
{
	auto &resource_manager = ResourcesManager::getInstanceRef();


	////***************Tutaj ustawcie sobie stage na jakim bêdziecie pracowaæ, az menu nie bedzie zrobione
	//przyklad: 
    //resource_manager.gameplay_stage.set();
	
    resource_manager.menu_stage.set();

	//******************

	while (resource_manager.window.isOpen())
	{
		if (!GameStage::stage_switch())
			resource_manager.exit_stage.set();

		input();

		if (!update())
			resource_manager.window.close();

		render();
	}

	ResourcesManager::deleteInstance();
	return 0;
}

void input()
{
	auto & resource = ResourcesManager::getInstanceRef();

	foo = std::make_shared<sf::Event>();
	resource.mainEvent = foo;

	while (resource.window.pollEvent(*foo))
	{
		if (foo->type == sf::Event::Closed)
			resource.exit_stage.set();

		GameStage::stage_input(*foo);
	}



}

bool update()
{
	const float dt = 0.01;
	static sf::Clock clock;
	static sf::Time time = sf::Time::Zero;

	time += clock.restart();
	while (time.asSeconds() >= dt)
	{
		if (!GameStage::stage_update(dt))
			return false;

		time -= sf::seconds(dt);
	}
	
	return true;
}

void fps()
{
	static sf::Clock clock;

	auto & resource = ResourcesManager::getInstanceRef();
	sf::Text fps;
	fps.setCharacterSize(2);
	fps.setFillColor(sf::Color::White);
	fps.setFont(resource.font);
	fps.setPosition(1, 1);
	std::stringstream ss;

	ss << (sf::seconds(1.0f) / clock.restart());

	fps.setString(ss.str());
	resource.window.draw(fps);
}

void render()
{
	auto & resource = ResourcesManager::getInstanceRef();

	resource.window.clear(sf::Color::Blue);

	GameStage::stage_render(resource.window);
	fps();
	resource.window.display();
}

