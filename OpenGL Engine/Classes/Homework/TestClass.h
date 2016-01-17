#pragma once

#include "../Renderable.h"

class TestClass : public Renderable {
public:
	TestClass();
	~TestClass();
protected:
	void Update();
};
