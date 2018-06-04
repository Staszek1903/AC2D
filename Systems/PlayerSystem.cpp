#include "Systems\PlayerSystem.h"

PlayerSystem::PlayerSystem()
{}

void PlayerSystem::update(entityx::EntityManager & en, entityx::EventManager & ev, double dt)
{
	Player::Handle player;
	Velocity::Handle vel;
	//Position::Handle pos;

	for (auto entity : en.entities_with_components(vel))
	{
		// move left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (vel->vel.x <= 0) {
				if (vel->vel.x < -player->walkSpeed)
					vel->vel.x -= player->walkSpeed*player->walkAcceleration*dt;
				else
					vel->vel.x = -player->walkSpeed;
			}
			else
				vel->vel.x += player->walkSpeed*player->deceleration*dt;
		}
		// move right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (vel->vel.x >= 0) {
				if (vel->vel.x < player->walkSpeed)
					vel->vel.x += player->walkSpeed*player->walkAcceleration*dt;
				else
					vel->vel.x = player->walkSpeed;
			}
			else
				vel->vel.x -= player->walkSpeed*player->deceleration*dt;
		}
		// Jump
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			vel->vel.y += player->jumpVelocity;
		}
	}

}
