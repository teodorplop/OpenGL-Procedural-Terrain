#include "Object.h"
#include "ObjectManager.h"

Object::Object() {
	ObjectManager::RegisterObject(this);
}
Object::~Object() {
	ObjectManager::UnregisterObject(this);
	delete vertexArray;
	delete indexBuffer;
}
void Object::SetShader(Shader* shader) {
	this->shader = shader;
}

void Object::Update() {
}
void Object::Draw() {
}