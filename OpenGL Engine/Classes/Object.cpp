#include "Object.h"
#include "ObjectManager.h"

Object::Object() {
	ObjectManager::RegisterObject(this);
	transform = new Transform();
}
Object::~Object() {
	ObjectManager::UnregisterObject(this);
	delete vertexArray;
	delete indexBuffer;
}
void Object::SetShader(Shader* shader) {
	this->shader = shader;
}
Shader* Object::GetShader() {
	return shader;
}

Transform* Object::GetTransform() {
	return transform;
}

void Object::Update() {
}
void Object::Draw() {
}