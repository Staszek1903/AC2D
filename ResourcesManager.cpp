#include "ResourcesManager.h"

ResourcesManager* ResourcesManager::instance = nullptr;

ResourcesManager::ResourcesManager() : window(sf::VideoMode(1366, 768, 32), "SFML Test", sf::Style::Titlebar | sf::Style::Close)
{
	window.setVerticalSyncEnabled(true);
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
