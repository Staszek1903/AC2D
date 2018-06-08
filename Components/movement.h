#pragma once

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <entityx\entityx.h>

struct AdvanceMovement : public entityx::Component<AdvanceMovement>
{
	float walkSpeed;
	float walkAcceleration;
	float deceleration;
	float jumpVelocity;

	bool moveLeft;
	bool moveRight;
	bool jumping;

	AdvanceMovement()
		: walkSpeed(3), 
		walkAcceleration(0.5), deceleration(1),
		jumpVelocity(3), 
		moveLeft(false), moveRight(false), jumping(false) {}
};

struct SimpleMovement : public entityx::Component<SimpleMovement>
{
	SimpleMovement() {}
};

#endif // !MOVEMENT_H
