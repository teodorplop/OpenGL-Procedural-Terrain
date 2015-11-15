#include "ObjectManager.h"

Object::Object() {
	ObjectManager::RegisterObject(this);
}
Object::~Object() {
	ObjectManager::UnregisterObject(this);
	glDeleteBuffers(1, &vboID);
}
void Object::SetShader(Shader* shader) {
	this->shader = shader;
}

void Object::Update() {
}
void Object::Draw() {
}