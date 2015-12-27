#include "ComponentManager.h"
#include <iostream>

ComponentManager* ComponentManager::instance = nullptr;

void ComponentManager::Start() {
	if (instance == nullptr) {
		instance = new ComponentManager();
	}
}

void ComponentManager::RegisterObject(Component* obj) {
	instance->objects.insert(obj);
}
void ComponentManager::UnregisterObject(Component* obj) {
	instance->objects.erase(obj);
}
void ComponentManager::Update() {
	for (auto obj : instance->objects) {
		obj->Update();
	}
}
void ComponentManager::CleanUp() {
	// TODO: This one is ugly.
	std::unordered_set<Component*> aux = instance->objects;
	for (auto obj : aux) {
		delete obj;
	}
}