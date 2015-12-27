#include "Renderable.h"
#include "Camera.h"
#include "GameObject.h"
#include "Renderer.h"

Renderable::Renderable() {
	Renderer::RegisterObject(this);
}

Renderable::~Renderable() {
	Renderer::UnregisterObject(this);
	delete vertexArray;
	delete indexBuffer;
}

void Renderable::Draw() {
	shader->Bind();
	vertexArray->Bind();
	indexBuffer->Bind();

	// Projection matrix
	shader->SetUniformMatrix4fv("gProj", Camera::GetMainCamera()->GetProjectionMatrix());
	// Camera matrix
	shader->SetUniformMatrix4fv("gCamera", Camera::GetMainCamera()->GetGameObject()->GetTransform()->GetMatrix());
	// World matrix
	shader->SetUniformMatrix4fv("gWorld", this->gameObject->GetTransform()->GetMatrix());

	glDrawElements(GL_TRIANGLE_FAN, indexBuffer->GetCount(), GL_UNSIGNED_INT, 0);

	indexBuffer->Unbind();
	vertexArray->Unbind();
	shader->Unbind();
}