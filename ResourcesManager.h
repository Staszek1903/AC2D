#pragma once

#include "LibsAndDeclarations.h"
#include "MenuStage.h"
#include "GameplayStage.h"
#include "ExitStage.h"

#include "vertex_data.h"

class ResourcesManager
{
private:
	ResourcesManager();
	ResourcesManager(const ResourcesManager&) = delete;
	ResourcesManager& operator=(const ResourcesManager&) = delete;
	ResourcesManager(ResourcesManager&&) = delete;
	ResourcesManager& operator=(ResourcesManager&&) = delete;
	~ResourcesManager();
	void loadVertexArray(sf::Vector2f v[], sf::Vector2f t[], int size);

private:
	static ResourcesManager *instance;

public:
	static ResourcesManager* getInstance();
	static ResourcesManager& getInstanceRef();
	static void deleteInstance();

public:
	sf::Font font;
	
	std::vector<sf::Texture> textures;
	std::vector<sf::VertexArray> vertexArrays;

	std::shared_ptr<sf::Event> mainEvent;

	sf::View camera;

	sf::RenderWindow window;
	MenuStage menu_stage;
	GameplayStage gameplay_stage;
	ExitStage exit_stage;
};
