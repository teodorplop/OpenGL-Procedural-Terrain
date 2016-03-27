#include "TerrainRenderer.h"

TerrainRenderer::TerrainRenderer(Shader* shader, Camera* camera) {
	this->shader = shader, this->camera = camera;
	shader->Bind();
	shader->SetUniformMatrix4fv("gProj", camera->GetProjectionMatrix());
	shader->SetUniform1i("backgroundSampler", 0);
	shader->SetUniform1i("rSampler", 1);
	shader->SetUniform1i("gSampler", 2);
	shader->SetUniform1i("bSampler", 3);
	shader->SetUniform1i("blendMapSampler", 4);
	shader->Unbind();
}

void TerrainRenderer::Draw(const std::vector<Terrain*>& terrains, Vector4 clipPlane) {
	EnableCulling(true);

	shader->Bind();
	shader->SetUniformMatrix4fv("gCamera", camera->GetTransform()->GetMatrix());
	shader->SetUniform3f("eyeWorldPosition", camera->GetTransform()->GetPosition());
	shader->SetUniform4f("clipPlane", clipPlane);

	for (unsigned int i = 0; i < terrains.size(); ++i) {
		shader->SetUniformMatrix4fv("gWorld", terrains[i]->GetWorldMatrix());

		RawModel* model = terrains[i]->GetModel();
		TerrainTexturePack* texturePack = terrains[i]->GetTexturePack();
		texturePack->GetBackgroundTexture()->Bind(0);
		texturePack->GetRTexture()->Bind(1);
		texturePack->GetGTexture()->Bind(2);
		texturePack->GetBTexture()->Bind(3);
		terrains[i]->GetBlendMap()->Bind(4);

		model->GetVertexArray()->Bind();
		model->GetIndexBuffer()->Bind();

		glDrawElements(GL_TRIANGLES, model->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);

		model->GetIndexBuffer()->Unbind();
		model->GetVertexArray()->Unbind();

		texturePack->GetBackgroundTexture()->Unbind();
		texturePack->GetRTexture()->Unbind();
		texturePack->GetGTexture()->Unbind();
		texturePack->GetBTexture()->Unbind();
		terrains[i]->GetBlendMap()->Unbind();
	}

	shader->Unbind();
}

void TerrainRenderer::EnableCulling(bool enabled) {
	if (enabled) {
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
	} else {
		glDisable(GL_CULL_FACE);
	}
}