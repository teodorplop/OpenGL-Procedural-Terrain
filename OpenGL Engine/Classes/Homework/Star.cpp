#include "Star.h"

Star::Star() {
	points.push_back(Vector3(0.0f, 0.0f, 0.0f));
	points.push_back(Vector3(0.0f, 0.1f, 0.0f));
	points.push_back(Vector3(0.025f, 0.025f, 0.0f));
	points.push_back(Vector3(0.1f, 0.025f, 0.0f));
	points.push_back(Vector3(0.05f, -0.025f, 0.0f));
	points.push_back(Vector3(0.0375f, -0.1f, 0.0f));
	points.push_back(Vector3(0.0f, -0.025f, 0.0f));
	points.push_back(Vector3(-0.0375f, -0.1f, 0.0f));
	points.push_back(Vector3(-0.05f, -0.025f, 0.0f));
	points.push_back(Vector3(-0.1f, 0.025f, 0.0f));
	points.push_back(Vector3(-0.025f, 0.025f, 0.0f));

	int NrPCT = (int)points.size();

	GLfloat vertices[100];
	GLfloat colors[100];

	int crt = 0;

	for (int i = 0; i < NrPCT; ++i) {
		vertices[crt++] = points[i].x;
		vertices[crt++] = points[i].y;
		vertices[crt++] = 0.0f;
		vertices[crt++] = 1.0f;

	}

	vertices[crt++] = vertices[4];
	vertices[crt++] = vertices[5];
	vertices[crt++] = vertices[6];
	vertices[crt++] = vertices[7];

	crt = 0;
	for (int i = 0; i <= NrPCT; ++i) {
		colors[crt++] = 1.0f;
		colors[crt++] = 1.0f;
		colors[crt++] = 1.0f;
		colors[crt++] = 1.0f;
	}

	GLuint  indices[100];
	for (int i = 0; i <= NrPCT + 1; ++i) {
		indices[i] = i;
	}

	vertexArray = new VertexArray();
	Buffer* positionBuffer = new Buffer(vertices, (NrPCT + 1) * 4, 4);
	Buffer* colorBuffer = new Buffer(colors, (NrPCT + 1) * 4, 4);
	indexBuffer = new IndexBuffer(indices, NrPCT + 2);

	vertexArray->AddBuffer(positionBuffer, 0);
	vertexArray->AddBuffer(colorBuffer, 1);

	shader = new Shader("Shaders/Shader.vert", "Shaders/Shader.frag");
}

void Star::Draw() {
	shader->Bind();
	vertexArray->Bind();
	indexBuffer->Bind();

	//shader->SetUniformMatrix4fv("gWorld", worldMatrix);
	shader->SetUniformMatrix4fv("gWorld", transform->matrix);
	glDrawElements(GL_TRIANGLE_FAN, indexBuffer->GetCount(), GL_UNSIGNED_INT, 0);

	indexBuffer->Unbind();
	vertexArray->Unbind();
	shader->Unbind();
}
void Star::Update() {
	timePassed++;
	if (timePassed == timer) {
		delete this;
	}
}

void Star::SetTimer(int timer) {
	this->timer = timer;
}