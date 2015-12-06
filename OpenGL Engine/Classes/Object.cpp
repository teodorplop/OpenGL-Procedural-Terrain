#include "Object.h"
#include "ObjectManager.h"

Object::Object() {
	ObjectManager::RegisterObject(this);
	translationMatrix = rotationMatrix = scaleMatrix = Matrix4(1.0f);
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

void Object::Update() {
}
void Object::Draw() {
}

void Object::SetPosition(Vector3 position) {
	this->position = position;
	this->translationMatrix = Matrix4::Translation(position);

	UpdateWorldMatrix();
}
Vector3 Object::GetPosition() {
	return position;
}
void Object::SetRotation(float angle, Vector3 axis) {
	this->rotation = Vector3(axis.x * angle, axis.y * angle, axis.z * angle);
	this->rotationMatrix = Matrix4::Rotation(angle, axis);

	UpdateWorldMatrix();
}
Vector3 Object::GetRotation() {
	return rotation;
}
void Object::SetScale(Vector3 scale) {
	this->scale = scale;
	this->scaleMatrix = Matrix4::Scale(scale);

	UpdateWorldMatrix();
}
Vector3 Object::GetScale() {
	return scale;
}

void Object::UpdateWorldMatrix() {
	worldMatrix = translationMatrix * rotationMatrix * scaleMatrix;
}