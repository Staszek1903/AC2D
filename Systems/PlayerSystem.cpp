#include "Systems\PlayerSystem.h"

PlayerSystem::PlayerSystem()
{}

void PlayerSystem::update(entityx::EntityManager & en, entityx::EventManager & ev, double dt)
{
	Player::Handle player;
	Velocity::Handle vel;
	Gravity::Handle grav;
	//Rotation::Handle rot;
	//Position::Handle pos;

	for (auto entity : en.entities_with_components(vel, player))
	{
		// move left
		if (sf::Keyboard::isKeyPressed(player->left)) {
			if (vel->vel.x <= 0) {
				vel->vel.x -= player->walkSpeed*player->walkAcceleration*dt;
				if (vel->vel.x < -player->walkSpeed)
					vel->vel.x = -player->walkSpeed;
			}
			else
				vel->vel.x -= player->walkSpeed*player->deceleration*dt;
		}
		// move right
		else if (sf::Keyboard::isKeyPressed(player->right)) {
			if (vel->vel.x >= 0) {
				vel->vel.x += player->walkSpeed*player->walkAcceleration*dt;
				if (vel->vel.x > player->walkSpeed)
					vel->vel.x = player->walkSpeed;
			}
			else
				vel->vel.x += player->walkSpeed*player->deceleration*dt;
		}
		// if not walking then stop
		else {
			if (vel->vel.x > 0.01)
				vel->vel.x -= player->walkSpeed*player->deceleration*dt;
			else if (vel->vel.x < -0.01)
				vel->vel.x += player->walkSpeed*player->deceleration*dt;
			else
				vel->vel.x = 0.0;
		}

		// Jump
		if (sf::Keyboard::isKeyPressed(player->jump /*&& isOnGround*/)) {
			vel->vel.y = -player->jumpVelocity;
		}
	}

}
