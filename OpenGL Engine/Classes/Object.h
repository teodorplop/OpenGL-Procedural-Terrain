#pragma once

#include "Transform.h"

class Object {
	friend class ObjectManager;

protected:
	virtual void Update();

public:
	Object();
	~Object();
};