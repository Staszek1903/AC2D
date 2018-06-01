#include "MenuStage.h"
#include "ResourcesManager.h"

MenuStage::MenuStage()
{
}

MenuStage::~MenuStage()
{
	release();
}

bool MenuStage::init()
{
    if (!font.loadFromFile("./resources/sansation.ttf"))
		return false;

	message.setFont(font);
    message.setCharacterSize(32);
	message.setPosition(10, 10);
	message.setFillColor(sf::Color::White);
	message.setString("SFML test - MenuStage\nPress space to start the game");


    ResourcesManager::getInstanceRef().camera.reset(sf::FloatRect(0, 0, 800, 600));

	return true;
}

bool MenuStage::update(float dt)
{
	ResourcesManager::getInstanceRef().window.setView(ResourcesManager::getInstanceRef().camera);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		ResourcesManager::getInstanceRef().gameplay_stage.set();
	}

	return true;
}

void MenuStage::input(sf::Event &)
{
}

void MenuStage::render(sf::RenderWindow & window)
{
    window.clear(sf::Color::Blue);
	window.draw(message);
}


void MenuStage::release()
{
	message = sf::Text();
	font = sf::Font();
}
