#include "Renderable.h"
#include "Camera.h"
#include "GameObject.h"
#include "Renderer.h"
#include "Texture.h"

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
	if (texture != NULL) {
		texture->Bind();
	}
	vertexArray->Bind();
	indexBuffer->Bind();

	// Projection matrix
	shader->SetUniformMatrix4fv("gProj", Camera::GetMainCamera()->GetProjectionMatrix());
	// Camera matrix
	shader->SetUniformMatrix4fv("gCamera", Camera::GetMainCamera()->GetGameObject()->GetTransform()->GetMatrix());
	// World matrix
	shader->SetUniformMatrix4fv("gWorld", this->gameObject->GetTransform()->GetMatrix());

	glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, 0);

	indexBuffer->Unbind();
	vertexArray->Unbind();
	if (texture != NULL) {
		texture->Unbind();
	}
	shader->Unbind();
}