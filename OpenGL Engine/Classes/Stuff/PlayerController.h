#pragma once

#include "../Object.h"
#include "../Transform.h"

class PlayerController : public Object {
private:
	static float runSpeed;
	static float turnSpeed;
	static float gravity;
	static float jumpPower;

	float currentSpeed, currentTurnSpeed, upwardsSpeed;
	Transform* target;

protected:
	void Update();

public:
	PlayerController(Transform* target);
};
