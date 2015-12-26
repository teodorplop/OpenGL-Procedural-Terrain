#include "Object.h"
#include "ObjectManager.h"
#include "Camera.h"

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
	shader->Bind();
	vertexArray->Bind();
	indexBuffer->Bind();

	// Projection matrix
	shader->SetUniformMatrix4fv("gProj", Camera::GetMainCamera()->GetProjectionMatrix());

	// Camera matrix
	Matrix4 camera = Camera::GetMainCamera()->GetTransform()->GetMatrix();
	camera.Invert();
	shader->SetUniformMatrix4fv("gCamera", camera);

	// World matrix
	shader->SetUniformMatrix4fv("gWorld", transform->GetMatrix());

	glDrawElements(GL_TRIANGLE_FAN, indexBuffer->GetCount(), GL_UNSIGNED_INT, 0);

	indexBuffer->Unbind();
	vertexArray->Unbind();
	shader->Unbind();
}