#include "ObjectManager.h"
#include <iostream>

ObjectManager* ObjectManager::instance = NULL;

ObjectManager* ObjectManager::GetInstance() {
	if (instance == NULL) {
		instance = new ObjectManager();
	}
	return instance;
}

void ObjectManager::RegisterObject(Object* obj) {
	objects.insert(obj);
}
void ObjectManager::UnregisterObject(Object* obj) {
	objects.erase(obj);
}
void ObjectManager::Update() {
	for (auto obj : objects) {
		obj->Update();
	}
}
void ObjectManager::CleanUp() {
	// TODO: This one is ugly.
	std::unordered_set<Object*> aux = objects;
	for (auto obj : aux) {
		delete obj;
	}
	objects.clear();
}