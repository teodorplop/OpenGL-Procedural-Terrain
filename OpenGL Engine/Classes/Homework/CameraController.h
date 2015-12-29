#pragma once

#include "../Component.h"

class CameraController : public Component {
public:
	CameraController();
	~CameraController();

private:
	void Update();
};
