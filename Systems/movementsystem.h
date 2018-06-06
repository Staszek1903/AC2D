#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include <entityx/entityx.h>
#include "Components\position.h"
#include "Components\velocity.h"

class MovementSystem: public entityx::System<MovementSystem>
{
public:
    MovementSystem();
    void update(entityx::EntityManager & en, entityx::EventManager & ev, double dt);
};

#endif // MOVEMENTSYSTEM_H
