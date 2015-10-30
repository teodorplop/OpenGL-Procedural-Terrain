#include "ObjectManager.h"

Object::Object() {
	ObjectManager::RegisterObject(this);
}

Object::~Object() {
	ObjectManager::UnregisterObject(this);
}

void Object::Update() {

}