#include "WaterRenderer.h"
#include "../Core/TimeFrame.h"

const float WaterRenderer::moveSpeed = 0.03f;

WaterRenderer::WaterRenderer(Shader* shader, Camera* camera, WaterFrameBuffer* waterFrameBuffer) {
	this->shader = shader, this->camera = camera, this->waterFrameBuffer = waterFrameBuffer;
	shader->Bind();
	shader->SetUniformMatrix4fv("gProj", camera->GetProjectionMatrix());
	shader->SetUniform1i("reflectionSampler", 0);
	shader->SetUniform1i("refractionSampler", 1);
	shader->SetUniform1i("dudvSampler", 2);
	shader->Unbind();

	this->dudvTexture = new Texture("Textures/Water/waterDUDV.png");
	this->moveFactor = 0.0f;
}

void WaterRenderer::Draw(const std::vector<Water*>& waters) {
	EnableCulling(true);

	moveFactor += moveSpeed * TimeFrame::deltaTime;
	moveFactor = fmod(moveFactor, 1.0f);

	shader->Bind();
	shader->SetUniformMatrix4fv("gCamera", camera->GetTransform()->GetMatrix());
	shader->SetUniform3f("eyeWorldPosition", camera->GetTransform()->GetPosition());
	shader->SetUniform1f("moveFactor", moveFactor);

	waterFrameBuffer->GetReflectionTexture()->Bind(0);
	waterFrameBuffer->GetRefractionTexture()->Bind(1);
	dudvTexture->Bind(2);

	for (unsigned int i = 0; i < waters.size(); ++i) {
		shader->SetUniformMatrix4fv("gWorld", waters[i]->GetWorldMatrix());

		RawModel* model = waters[i]->GetModel();
		model->GetVertexArray()->Bind();
		model->GetIndexBuffer()->Bind();

		glDrawElements(GL_TRIANGLES, model->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);

		model->GetIndexBuffer()->Unbind();
		model->GetVertexArray()->Unbind();
	}

	waterFrameBuffer->GetReflectionTexture()->Unbind();
	waterFrameBuffer->GetRefractionTexture()->Unbind();
	dudvTexture->Unbind();

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