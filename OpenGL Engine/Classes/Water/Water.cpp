#include "Water.h"
#include "../Buffers/VertexArray.h"
#include "../Buffers/Buffer.h"
#include "../Buffers/IndexBuffer.h"
#include <vector>

const float Water::size = 1024.0f;

Water::Water(int gridX, int gridZ) {
	this->x = gridX * size, this->z = gridZ * size;
	this->worldMatrix = Matrix4::Translation(Vector3(this->x, 0.0f, this->z));

	std::vector<Vector2> vertices;
	std::vector<Vector2> uvs;
	std::vector<Vector3> normals;
	std::vector<unsigned int> indices;
	for (int i = 0; i < 2; ++i) {
		float x = this->x + i * size;
		for (int j = 0; j < 2; ++j) {
			float z = this->z + j * size;
			vertices.push_back(Vector2(x, z));
			uvs.push_back(Vector2((float)i, (float)j));
			normals.push_back(Vector3(0.0f, 1.0f, 0.0f));
		}
	}
	indices.push_back(0);
	indices.push_back(2);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);
	indices.push_back(1);

	VertexArray* vertexArray = new VertexArray();
	Buffer* verticesBuffer = new Buffer(vertices);
	Buffer* uvsBuffer = new Buffer(uvs);
	Buffer* normalsBuffer = new Buffer(normals);
	IndexBuffer* indexBuffer = new IndexBuffer(indices);
	vertexArray->AddBuffer(verticesBuffer, 0);
	vertexArray->AddBuffer(uvsBuffer, 1);
	vertexArray->AddBuffer(normalsBuffer, 2);

	model = new RawModel(vertexArray, indexBuffer);
}

Water::~Water() {
}

RawModel* Water::GetModel() {
	return model;
}
const Matrix4& Water::GetWorldMatrix() const {
	return worldMatrix;
}