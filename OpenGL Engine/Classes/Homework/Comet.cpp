#include "Comet.h"
#include "Star.h"

Comet::Comet() {
	GLfloat vertices[] = {
		0.0f, 0.0f, 0.0f, 1.0f,
		0.35f, 0.1f, 0.0f, 1.0f,
		0.35f, -0.1f, 0.0f, 1.0f
	};
	GLfloat colors[] = {
		1.0f, 0.6f, 0.0f, 1.0f,
		1.0f, 0.6f, 0.0f, 1.0f,
		1.0f, 0.6f, 0.0f, 1.0f
	};
	GLuint indices[] = {
		0, 1, 2
	};

	vertexArray = new VertexArray();
	Buffer* positionBuffer = new Buffer(vertices, 3 * 4, 4);
	Buffer* colorBuffer = new Buffer(colors, 3 * 4, 4);
	indexBuffer = new IndexBuffer(indices, 3);

	vertexArray->AddBuffer(positionBuffer, 0);
	vertexArray->AddBuffer(colorBuffer, 1);

	shader = new Shader("Shaders/Shader.vert", "Shaders/Shader.frag");
}

void Comet::Draw() {
	shader->Bind();
	vertexArray->Bind();
	indexBuffer->Bind();

	//shader->SetUniformMatrix4fv("gWorld", worldMatrix);
	shader->SetUniformMatrix4fv("gWorld", transform->matrix);
	glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, 0);

	indexBuffer->Unbind();
	vertexArray->Unbind();
	shader->Unbind();
}

int frames = 0;
void Comet::Update() {
	transform->TranslateBy(Vector3(-0.002f, -0.0014f, 0.0f));

	++frames;
	if (frames >= 345) {
		delete this;

		for (int i = 0; i < 20; ++i) {
			Star* star = new Star();
			star->SetTimer(1000000);
			Vector3 position = Vector3((float)(rand() % 300) / 1000.0f + 0.5f, (float)(rand() % 300) / 1000.0f - 0.2f);
			Vector3 scale = Vector3((float)(rand() % 300) / 1000.0f + 0.15f, (float)(rand() % 300) / 1000.0f + 0.15f);
			star->GetTransform()->TranslateTo(position);
			star->GetTransform()->ScaleTo(scale);
		}
	}
}