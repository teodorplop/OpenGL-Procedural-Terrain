#include "Renderable.h"
#include "Camera.h"
#include "GameObject.h"
#include "Renderer.h"
#include "Texture.h"

#include "Shaders.h"

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
	
	Shaders::GetInstance()->shader->SetUniformMatrix4fv("gProj", Camera::GetMainCamera()->GetProjectionMatrix());
	// Camera matrix
	Shaders::GetInstance()->shader->SetUniformMatrix4fv("gCamera", Camera::GetMainCamera()->GetGameObject()->GetTransform()->GetMatrix());
	// World matrix
	Shaders::GetInstance()->shader->SetUniformMatrix4fv("gWorld", this->gameObject->GetTransform()->GetMatrix());

	Shaders::GetInstance()->shader->SetUniformDirectionalLight("directionalLight", DirectionalLight(Color::red, 0.5f, Vector3(-1.0f, -1.0f, 0.0f), 0.75f));

	glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, 0);

	indexBuffer->Unbind();
	vertexArray->Unbind();
	if (texture != NULL) {
		texture->Unbind();
	}
	shader->Unbind();
}