#pragma once

#include "Transform.h"

class Object {
	friend class ObjectManager;

private:
	Transform* transform;

protected:
	virtual void Update();

public:
	Transform* GetTransform();
	Object();
	~Object();
};