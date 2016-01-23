#include "Object.h"
#include "Core/ObjectManager.h"

Object::Object() {
	ObjectManager::GetInstance()->RegisterObject(this);

	transform = new Transform();
}
Object::~Object() {
	ObjectManager::GetInstance()->UnregisterObject(this);

	delete transform;
}

Transform* Object::GetTransform() {
	return transform;
}

void Object::Update() {
}