#ifndef __TEST_OBJECT_H__
#define __TEST_OBJECT_H__

#include "Renderable.h"
#include "Color.h"
#include <GL/glew.h>

class TestObject : public Renderable {
public:
	TestObject();
	~TestObject();
};

#endif //__TEST_OBJECT_H__