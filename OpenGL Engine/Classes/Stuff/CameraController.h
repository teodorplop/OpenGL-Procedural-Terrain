#pragma once

#include "../Utils/Math/Vector3.h"
#include "../Object.h"
#include "../Transform.h"

class CameraController : public Object {
public:
	CameraController(Transform* camera);

private:
	float distanceFromPlayer;
	float angleAroundPlayer;
	float pitch;
	float yaw;

	Transform* camera;

protected:
	void Update();
};