#include "GameObject.h"
#include "ComponentManager.h"
#include "Camera.h"
#include <typeinfo>

GameObject::GameObject() {
	transform = new Transform();
}
GameObject::~GameObject() {
	delete transform;
}

Component* GameObject::GetComponent(std::string name) {
	return components[name];
}
void GameObject::AddComponent(Component* component) {
	std::string name = typeid(*component).name();
	if (components.find(name) != components.end()) {
		fprintf(stderr, "Component %s already exists!", name.c_str());
	} else {
		component->gameObject = this;
		components[name] = component;
	}
}
void GameObject::RemoveComponent(Component* component) {
	RemoveComponent(typeid(*component).name());
}
void GameObject::RemoveComponent(std::string name) {
	if (name.find("class") == -1) {
		name = "class " + name;
	}

	if (components.find(name) == components.end()) {
		fprintf(stderr, "Component %s does not exist!", name.c_str());
	} else {
		delete components[name];
		components.erase(name);
	}
}

Transform* GameObject::GetTransform() {
	return transform;
}