#pragma once

#include "../Object.h"
#include "../Utils/Math/Vector3.h"

class CameraController : public Object {
public:
	CameraController();
	~CameraController();

private:
	void Update();
};