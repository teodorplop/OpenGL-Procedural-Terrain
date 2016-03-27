#pragma once

#include "../Utils/Math/Vector3.h"
#include "../Object.h"
#include "../Transform.h"

class CameraController : public Object {
public:
	CameraController(Transform* camera);

private:
	Transform* camera;

protected:
	void Update();
};