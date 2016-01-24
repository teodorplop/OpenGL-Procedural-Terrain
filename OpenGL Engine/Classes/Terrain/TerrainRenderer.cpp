#include "TerrainRenderer.h"

TerrainRenderer::TerrainRenderer(Shader* shader, Camera* camera) {
	this->shader = shader, this->camera = camera;
	shader->Bind();
	shader->SetUniformMatrix4fv("gProj", camera->GetProjectionMatrix());
	shader->Unbind();
}

void TerrainRenderer::Draw(const std::vector<Terrain*>& terrains) {
	shader->Bind();
	shader->SetUniformMatrix4fv("gCamera", camera->GetTransform()->GetMatrix());

	for (unsigned int i = 0; i < terrains.size(); ++i) {
		shader->SetUniformMatrix4fv("gWorld", terrains[i]->GetWorldMatrix());

		RawModel* model = terrains[i]->GetModel();
		Texture* texture = terrains[i]->GetTexture();

		texture->Bind();

		model->GetVertexArray()->Bind();
		model->GetIndexBuffer()->Bind();

		glDrawElements(GL_TRIANGLES, model->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);

		model->GetIndexBuffer()->Unbind();
		model->GetVertexArray()->Unbind();

		texture->Unbind();
	}

	shader->Unbind();
}