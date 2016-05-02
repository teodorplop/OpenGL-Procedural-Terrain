#include "RawModel.h"
#include "Camera.h"
#include "Core/Renderer.h"
#include "Utils\ObjLoader.h"
#include <vector>

RawModel::RawModel(VertexArray* vertexArray, IndexBuffer* indexBuffer) {
	this->vertexArray = vertexArray, this->indexBuffer = indexBuffer;
}
RawModel::~RawModel() {
	delete vertexArray;
	delete indexBuffer;
}

VertexArray* RawModel::GetVertexArray() {
	return vertexArray;
}
IndexBuffer* RawModel::GetIndexBuffer() {
	return indexBuffer;
}

RawModel* RawModel::LoadQuad() {
	std::vector<Vector2> vertices;
	std::vector<Vector2> uvs;
	std::vector<unsigned int> indices;

	for (int i = -1; i < 2; i += 2) {
		for (int j = -1; j < 2; j += 2) {
			vertices.push_back(Vector2((float)i, (float)j));
		}
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			uvs.push_back(Vector2((float)i, (float)j));
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
	IndexBuffer* indexBuffer = new IndexBuffer(indices);
	vertexArray->AddBuffer(verticesBuffer, 0);
	vertexArray->AddBuffer(uvsBuffer, 1);

	return new RawModel(vertexArray, indexBuffer);
}

RawModel* RawModel::LoadFromObj(const char* filename) {
	std::vector<Vector4> vertices;
	std::vector<Vector2> uvs;
	std::vector<Vector3> normals;
	std::vector<unsigned int> indices;

	bool success = ObjLoader::LoadObj(filename, vertices, uvs, normals, indices);
	if (!success) {
		fprintf(stderr, "Failed to produce RawModel");
		return NULL;
	}

	VertexArray* vertexArray = new VertexArray();
	Buffer* verticesBuffer = new Buffer(vertices);
	Buffer* uvsBuffer = new Buffer(uvs);
	Buffer* normalsBuffer = new Buffer(normals);
	IndexBuffer* indexBuffer = new IndexBuffer(indices);
	vertexArray->AddBuffer(verticesBuffer, 0);
	vertexArray->AddBuffer(uvsBuffer, 1);
	vertexArray->AddBuffer(normalsBuffer, 2);

	return new RawModel(vertexArray, indexBuffer);
}