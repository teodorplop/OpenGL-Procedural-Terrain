#pragma once

#include "Object.h"
#include "Transform.h"
#include "TexturedModel.h"

class GameObject : public Object {
private:
	Transform* transform;
	TexturedModel* model;

public:
	GameObject(TexturedModel* model);
	~GameObject();

	Transform* GetTransform();
	TexturedModel* GetModel();
};

