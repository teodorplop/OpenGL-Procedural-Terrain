#include "RawModel.h"
#include "Camera.h"
#include "Core/Renderer.h"

RawModel::RawModel() {
	Renderer::GetInstance()->RegisterObject(this);
}

RawModel::~RawModel() {
	Renderer::GetInstance()->UnregisterObject(this);
}

void RawModel::Draw() {
	shader->Bind();
	vertexArray->Bind();
	indexBuffer->Bind();

	// Projection matrix
	shader->SetUniformMatrix4fv("gProj", Camera::GetMainCamera()->GetProjectionMatrix());
	// Camera matrix
	shader->SetUniformMatrix4fv("gCamera", Camera::GetMainCamera()->GetTransform()->GetMatrix());
	// World matrix
	shader->SetUniformMatrix4fv("gWorld", GetTransform()->GetMatrix());

	glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, 0);

	indexBuffer->Unbind();
	vertexArray->Unbind();
	shader->Unbind();
}