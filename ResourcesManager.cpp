#include "ResourcesManager.h"

ResourcesManager* ResourcesManager::instance = nullptr;

ResourcesManager::ResourcesManager()
{
	//window.setVerticalSyncEnabled(false);
	font.loadFromFile("./resources/sansation.ttf");

	sf::ContextSettings settings;
	settings.antialiasingLevel = 2;

	window.create(sf::VideoMode(1366, 768, 32), "AC 0.00001 ver. alfa", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);

}

ResourcesManager::~ResourcesManager()
{
}

ResourcesManager* ResourcesManager::getInstance()
{
	if (!instance) instance = new ResourcesManager();

	return instance;
}

ResourcesManager& ResourcesManager::getInstanceRef()
{
	return *getInstance();
}

void ResourcesManager::deleteInstance()
{
	delete instance;
}
