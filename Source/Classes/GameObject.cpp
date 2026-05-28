#include "GameObject.h"

GameObject::GameObject(TexturedModel* model) {
	transform = new Transform();
	this->model = model;
}
GameObject::~GameObject() {
	delete transform;
}

Transform* GameObject::GetTransform() {
	return transform;
}
TexturedModel* GameObject::GetModel() {
	return model;
}