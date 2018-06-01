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
	message.setCharacterSize(40);
	message.setPosition(170.f, 150.f);
	message.setFillColor(sf::Color::White);
	message.setString("SFML test - MenuStage\nPress space to start the game");

	return true;
}

bool MenuStage::update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		ResourcesManager::getInstanceRef().gameplay_stage.set();
	}

	return true;
}

void MenuStage::draw(sf::RenderWindow &window)
{
	window.clear(sf::Color(255, 0, 0));
	window.draw(message);
}

void MenuStage::release()
{
	message = sf::Text();
	font = sf::Font();
}
