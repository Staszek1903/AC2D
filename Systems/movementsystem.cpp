#include "movementsystem.h"

MovementSystem::MovementSystem()
{

}

void MovementSystem::update(entityx::EntityManager &en, entityx::EventManager &ev, double dt)
{
     Position::Handle pos;
     Velocity::Handle vel;
	 AdvanceMovement::Handle mov;
	 SimpleMovement::Handle smov;
     //Rotation::Handel rot;
     //AngularVelocity::Handle angvel;

    for (auto entity : en.entities_with_components(pos, vel, mov))
    {
		pos->pos += vel->vel;// *dt;
		// move left
		if (mov->moveLeft) {
			if (vel->vel.x <= 0) {
				vel->vel.x -= mov->walkSpeed*mov->walkAcceleration*dt;
				if (vel->vel.x < -mov->walkSpeed)
					vel->vel.x = -mov->walkSpeed;
			}
			else
				vel->vel.x -= mov->walkSpeed*mov->deceleration*dt;
		}
		// move right
		else if (mov->moveRight) {
			if (vel->vel.x >= 0) {
				vel->vel.x += mov->walkSpeed*mov->walkAcceleration*dt;
				if (vel->vel.x > mov->walkSpeed)
					vel->vel.x = mov->walkSpeed;
			}
			else
				vel->vel.x += mov->walkSpeed*mov->deceleration*dt;
		}
		// if not walking then stop
		else {
			if (vel->vel.x > 0.01)
				vel->vel.x -= mov->walkSpeed*mov->deceleration*dt;
			else if (vel->vel.x < -0.01)
				vel->vel.x += mov->walkSpeed*mov->deceleration*dt;
			else
				vel->vel.x = 0.0;
		}

		// Jump
		if (mov->jumping /*&& isOnGround*/) {
			vel->vel.y = -mov->jumpVelocity;
		}
    }

	for (auto entity : en.entities_with_components(pos, vel, smov))
	{
		pos->pos += vel->vel;
	}
}
