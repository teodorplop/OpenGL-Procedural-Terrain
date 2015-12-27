#include "Component.h"
#include "ComponentManager.h"

Component::Component() {
	ComponentManager::RegisterObject(this);
}

Component::~Component() {
	ComponentManager::UnregisterObject(this);
}

void Component::Update() {
}
GameObject* Component::GetGameObject() {
	return gameObject;
}