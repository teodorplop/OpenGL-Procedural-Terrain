#pragma once

#include "../Object.h"
#include<vector>
#include "../Utils/Math/Vector3.h"

class Star : public Object {
	std::vector<Vector3> points;
	int timer, timePassed;
public:
	Star();
	void SetTimer(int timer);
private:
	void Draw();
	void Update();
};

