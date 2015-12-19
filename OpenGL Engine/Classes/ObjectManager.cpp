#include "ObjectManager.h"

ObjectManager* ObjectManager::instance = nullptr;

void ObjectManager::Start() {
	if (instance == nullptr) {
		instance = new ObjectManager();
	}
}

void ObjectManager::RegisterObject(Object* obj) {
	instance->objects.insert(obj);
}
void ObjectManager::UnregisterObject(Object* obj) {
	instance->objects.erase(obj);
}
void ObjectManager::Update() {
	for (auto obj : instance->objects) {
		obj->Update();
	}
}
void ObjectManager::Draw() {
	for (auto obj : instance->objects) {
		obj->Draw();
	}
}
void ObjectManager::CleanUp() {
	// TODO: This one is ugly.
	std::unordered_set<Object*> aux = instance->objects;
	for (auto obj : aux) {
		delete obj;
	}
}