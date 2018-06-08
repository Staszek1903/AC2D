#include "Systems\PlayerSystem.h"

PlayerSystem::PlayerSystem()
{}

void PlayerSystem::update(entityx::EntityManager & en, entityx::EventManager & ev, double dt)
{
	Player::Handle player;
	Velocity::Handle vel;
	AdvanceMovement::Handle mov;

	for (auto entity : en.entities_with_components(vel, player, mov))
	{
		// move left
		if (sf::Keyboard::isKeyPressed(player->left))
			mov->moveLeft = true;
		else
			mov->moveLeft = false;
		// move right
		if (sf::Keyboard::isKeyPressed(player->right))
			mov->moveRight = true;
		else
			mov->moveRight = false;

		// Jump
		if (sf::Keyboard::isKeyPressed(player->jump))
			mov->jumping = true;
		else
			mov->jumping = false;
	}

}
