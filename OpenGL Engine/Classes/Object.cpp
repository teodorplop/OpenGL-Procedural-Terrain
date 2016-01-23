#include "Object.h"
#include "Core/ObjectManager.h"

Object::Object() {
	ObjectManager::GetInstance()->RegisterObject(this);
}
Object::~Object() {
	ObjectManager::GetInstance()->UnregisterObject(this);
}

void Object::Update() {
}