#pragma once

#include "../Utils/Math/Vector3.h"
#include "../Object.h"
#include "../Camera.h"

class CameraController : public Object {
public:
	CameraController(Camera* target);
	~CameraController();

private:
	Camera* target;

protected:
	void Update();
};