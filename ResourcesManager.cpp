#include "ResourcesManager.h"

ResourcesManager* ResourcesManager::instance = nullptr;

ResourcesManager::ResourcesManager()
{
	//window.setVerticalSyncEnabled(false);
	font.loadFromFile("./resources/sansation.ttf");

	sf::Texture t1;
	t1.loadFromFile("./resources/texture.png");
	textures.push_back(t1);
	
	loadVertexArray(quad_vertex, quad_texture, 4);

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

void ResourcesManager::loadVertexArray(sf::Vector2f v[], sf::Vector2f t[], int size)
{
	sf::VertexArray va(sf::TriangleFan, size);
	for (int i = 0; i<size; ++i)
	{
		va[i].position = v[i];
		va[i].texCoords = t[i];
	}

	vertexArrays.push_back(va);
}
