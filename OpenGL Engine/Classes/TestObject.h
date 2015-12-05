#ifndef __TEST_OBJECT_H__
#define __TEST_OBJECT_H__

#include "Object.h"
#include <GL/glew.h>

class TestObject : public Object {
public:
	TestObject();
	~TestObject();
protected:
	void Draw();
	void Update();
};

#endif //__TEST_OBJECT_H__