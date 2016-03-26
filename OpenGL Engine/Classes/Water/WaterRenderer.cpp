#include "WaterRenderer.h"

WaterRenderer::WaterRenderer(Shader* shader, Camera* camera) {
	this->shader = shader, this->camera = camera;
	shader->Bind();
	shader->SetUniformMatrix4fv("gProj", camera->GetProjectionMatrix());
	shader->Unbind();
}

void WaterRenderer::Draw(const std::vector<Water*>& waters) {
	EnableCulling(true);

	shader->Bind();
	shader->SetUniformMatrix4fv("gCamera", camera->GetTransform()->GetMatrix());
	shader->SetUniform3f("eyeWorldPosition", camera->GetTransform()->GetPosition());

	for (unsigned int i = 0; i < waters.size(); ++i) {
		shader->SetUniformMatrix4fv("gWorld", waters[i]->GetWorldMatrix());

		RawModel* model = waters[i]->GetModel();
		model->GetVertexArray()->Bind();
		model->GetIndexBuffer()->Bind();

		glDrawElements(GL_TRIANGLES, model->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);

		model->GetIndexBuffer()->Unbind();
		model->GetVertexArray()->Unbind();
	}

	shader->Unbind();
}

void WaterRenderer::EnableCulling(bool enabled) {
	if (enabled) {
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
	}
	else {
		glDisable(GL_CULL_FACE);
	}
}