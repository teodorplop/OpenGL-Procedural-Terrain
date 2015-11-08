#include "ObjectManager.h"

Object::Object() {
	ObjectManager::RegisterObject(this);
}
Object::~Object() {
	ObjectManager::UnregisterObject(this);
}
void Object::SetShader(const char* vertexPath, const char* fragmentPath) {
	shader = new Shader(vertexPath, fragmentPath);
}

void Object::Update() {
}
void Object::Draw() {
}