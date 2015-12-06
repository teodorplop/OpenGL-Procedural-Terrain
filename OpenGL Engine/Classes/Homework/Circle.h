#pragma once

#include "../Utils/Math/Vector3.h"
#include "../Utils/Math/math_h.h"
#include<vector>
#include <GL/glew.h>
#include "../Object.h"

class Circle : public Object
{
	Vector3 center;
	float radius;
	static int nrPct;
public:
	Circle();
	Circle(Vector3 _center, float _radius);
	~Circle();
	void Draw();
	std::vector<Vector3> Circumference();

};

