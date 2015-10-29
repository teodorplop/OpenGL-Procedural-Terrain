#include "ObjectManager.h"

ObjectManager* ObjectManager::instance = nullptr;

void ObjectManager::Initialize() {
	if (instance == nullptr) {
		instance = new ObjectManager();
	}
}

void ObjectManager::Register(Object* obj) {
	objects.push_back(obj);
}