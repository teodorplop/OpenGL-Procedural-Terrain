#pragma once

#include "DirectionalLight.h"

class Lights {
private:
	static DirectionalLight directionalLight;
public:
	static void AddLight(const DirectionalLight& light);
	static DirectionalLight GetDirectionalLight();
	Lights();
	~Lights();
};

