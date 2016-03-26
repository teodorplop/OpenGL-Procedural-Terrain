#include "UIRenderer.h"

UIRenderer::UIRenderer(Shader* shader) {
	this->shader = shader;
}

void UIRenderer::Draw(const std::vector<UITexture*>& objects) {
	EnableCulling(true);

	shader->Bind();
	for (unsigned int i = 0; i < objects.size(); ++i) {
		GameObject* gameObject = objects[i]->GetGameObject();
		shader->SetUniformMatrix4fv("gWorld", gameObject->GetTransform()->GetMatrix());

		RawModel* model = gameObject->GetModel()->GetRawModel();
		Texture* texture = gameObject->GetModel()->GetTexture();

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

void UIRenderer::EnableCulling(bool enabled) {
	if (enabled) {
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
	}
	else {
		glDisable(GL_CULL_FACE);
	}
}