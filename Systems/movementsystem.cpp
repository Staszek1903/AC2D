#include "movementsystem.h"

MovementSystem::MovementSystem()
{

}

void MovementSystem::update(entityx::EntityManager &en, entityx::EventManager &ev, double dt)
{
     Position::Handle pos;
     Velocity::Handle vel;
     //Rotation::Handel rot;
     //AngularVelocity::Handle angvel;

    for (auto entity : en.entities_with_components(pos, vel))
    {
		pos->pos += vel->vel;// *dt;
        //rot->degree += angvel->degree
    }
}
