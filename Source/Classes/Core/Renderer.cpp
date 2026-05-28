#include "Renderer.h"

Renderer::Renderer(Shader* shader, Camera* camera) {
	this->shader = shader, this->camera = camera;

	shader->Bind();
	shader->SetUniformMatrix4fv("gProj", camera->GetProjectionMatrix());
	shader->Unbind();
}

void Renderer::Draw(const std::vector<GameObject*>&  objects, Vector4 clipPlane) {
	EnableCulling(true);
	shader->Bind();
	shader->SetUniformMatrix4fv("gCamera", camera->GetTransform()->GetMatrix());
	shader->SetUniform3f("eyeWorldPosition", camera->GetTransform()->GetPosition());
	shader->SetUniform4f("clipPlane", clipPlane);

	for (unsigned int i = 0; i < objects.size(); ++i) {
		shader->SetUniformMatrix4fv("gWorld", objects[i]->GetTransform()->GetMatrix());

		RawModel* model = objects[i]->GetModel()->GetRawModel();
		Texture* texture = objects[i]->GetModel()->GetTexture();

		if (texture->HasTransparency()) {
			EnableCulling(false);
		}

		texture->Bind();
		model->GetVertexArray()->Bind();
		model->GetIndexBuffer()->Bind();

		glDrawElements(GL_TRIANGLES, model->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);

		model->GetIndexBuffer()->Unbind();
		model->GetVertexArray()->Unbind();
		texture->Unbind();

		if (texture->HasTransparency()) {
			EnableCulling(true);
		}
	}

	shader->Unbind();
}

void Renderer::EnableCulling(bool enabled) {
	if (enabled) {
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
	} else {
		glDisable(GL_CULL_FACE);
	}
}