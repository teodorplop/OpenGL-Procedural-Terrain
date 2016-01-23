#include "Renderer.h"

void Renderer::Draw(RawModel* model) {
	model->GetVertexArray()->Bind();
	model->GetIndexBuffer()->Bind();

	glDrawElements(GL_TRIANGLES, model->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);

	model->GetIndexBuffer()->Unbind();
	model->GetVertexArray()->Unbind();
}
void Renderer::Draw(TexturedModel* texturedModel) {
	RawModel* model = texturedModel->GetModel();
	Texture* texture = texturedModel->GetTexture();

	texture->Bind();

	model->GetVertexArray()->Bind();
	model->GetIndexBuffer()->Bind();

	glDrawElements(GL_TRIANGLES, model->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);

	model->GetIndexBuffer()->Unbind();
	model->GetVertexArray()->Unbind();

	texture->Unbind();
}