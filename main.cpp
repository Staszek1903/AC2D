#include "LibsAndDeclarations.h"

#include "ResourcesManager.h"

int main(void)
{
	// Getting resources_manager reference
	auto p = ResourcesManager::getInstance();

	auto &resources_manager = ResourcesManager::getInstanceRef();
	// Setting first (MenuStage) state
	resources_manager.menu_stage.set();

	sf::Clock clock;
	bool is_playing = false;
	while (resources_manager.window.isOpen())
	{
		// EVENTS
		{
			sf::Event event;
			while (resources_manager.window.pollEvent(event))
			{
				// Window closed or escape key pressed: ExitStage
				if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
				{
					resources_manager.exit_stage.set();
					break;
				}
			}
		}

		// UPDATE
		{
			float delta_time = clock.restart().asSeconds();
			resources_manager.window.clear(sf::Color(0, 0, 0));
			if (GameStage::run(delta_time, resources_manager.window))
			{
				resources_manager.window.display();
			}
			else
			{
				resources_manager.window.close();
				break;
			}
		}
	}

	// Deleteing singleton instance...
	ResourcesManager::deleteInstance();

	return 0;
}
