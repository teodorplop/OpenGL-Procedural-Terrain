#ifndef __TEST_COMPONENT_H__
#define __TEST_COMPONENT_H__

#include "..\Renderable.h"

class TestComponent : public Renderable {
public:
	TestComponent();
	~TestComponent();

private:
	void Update();
};

#endif // __TEST_COMPONENT_H__