#include "ObjectManager.h"

ObjectManager* ObjectManager::instance = nullptr;

void ObjectManager::Initialize() {
	if (instance == nullptr) {
		instance = new ObjectManager();
	}
}

void ObjectManager::RegisterObject(Object* obj) {
	instance->objects.push_back(obj);
}
void ObjectManager::UnregisterObject(Object* obj) {

}
void ObjectManager::Update() {
	for (int i = 0; i < (int)instance->objects.size(); ++i) {
		instance->objects[i]->Update();
	}
}