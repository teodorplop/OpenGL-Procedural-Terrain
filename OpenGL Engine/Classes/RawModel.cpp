#include "RawModel.h"
#include "Camera.h"
#include "Core/Renderer.h"
#include "Utils\ObjLoader.h"
#include <vector>

RawModel::RawModel(VertexArray* vertexArray, IndexBuffer* indexBuffer) {
	this->vertexArray = vertexArray, this->indexBuffer = indexBuffer;
}
VertexArray* RawModel::GetVertexArray() {
	return vertexArray;
}
IndexBuffer* RawModel::GetIndexBuffer() {
	return indexBuffer;
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