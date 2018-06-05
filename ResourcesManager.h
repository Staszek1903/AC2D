#pragma once

#include "LibsAndDeclarations.h"
#include "MenuStage.h"
#include "GameplayStage.h"
#include "ExitStage.h"

class ResourcesManager
{
private:
	ResourcesManager();
	ResourcesManager(const ResourcesManager&) = delete;
	ResourcesManager& operator=(const ResourcesManager&) = delete;
	ResourcesManager(ResourcesManager&&) = delete;
	ResourcesManager& operator=(ResourcesManager&&) = delete;
	~ResourcesManager();

private:
	static ResourcesManager *instance;

public:
	static ResourcesManager* getInstance();
	static ResourcesManager& getInstanceRef();
	static void deleteInstance();

public:
	sf::Font font;

	std::shared_ptr<sf::Event> mainEvent;

	sf::View camera;

	sf::RenderWindow window;
	MenuStage menu_stage;
	GameplayStage gameplay_stage;
	ExitStage exit_stage;
};
