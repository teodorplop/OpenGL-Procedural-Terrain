#include "ObjectManager.h"

ObjectManager* ObjectManager::instance = nullptr;

void ObjectManager::Start() {
	if (instance == nullptr) {
		instance = new ObjectManager();
	}
}

void ObjectManager::RegisterObject(Object* obj) {
	instance->objects.push_back(obj);
}
void ObjectManager::UnregisterObject(Object* obj) {
	int position = -1;
	for (int i = 0; i < (int)instance->objects.size(); ++i) {
		if (instance->objects[i] == obj) {
			position = i;
		}
	}

	instance->objects.erase(instance->objects.begin() + position);
}
void ObjectManager::Update() {
	for (int i = 0; i < (int)instance->objects.size(); ++i) {
		instance->objects[i]->Update();
		instance->objects[i]->Draw();
	}
}