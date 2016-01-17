#include "Component.h"
#include "ComponentManager.h"

Component::Component() {
	ComponentManager::RegisterObject(this);
	SetActive(true);
}

Component::~Component() {
	ComponentManager::UnregisterObject(this);
}

void Component::Update() {
}
GameObject* Component::GetGameObject() {
	return gameObject;
}

bool Component::IsActive() {
	return isActive;
}
void Component::SetActive(bool isActive) {
	this->isActive = isActive;
}