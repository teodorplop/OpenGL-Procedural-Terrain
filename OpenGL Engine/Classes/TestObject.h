#ifndef __TEST_OBJECT_H__
#define __TEST_OBJECT_H__

#include "Object.h"
#include "Color.h"
#include <GL/glew.h>

class TestObject : public Object {
public:
	TestObject(Color color = Color::blue);
	~TestObject();
};

#endif //__TEST_OBJECT_H__