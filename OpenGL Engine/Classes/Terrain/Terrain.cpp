#include "Terrain.h"
#include "../Buffers/VertexArray.h"
#include "../Buffers/Buffer.h"
#include "../Buffers/IndexBuffer.h"
#include <vector>

// total square size
float Terrain::size = 800;
// number of small squares is cells * cells
int Terrain::cells = 64;

Terrain::Terrain(int gridX, int gridZ, TerrainTexturePack* texturePack, Texture* blendMap) {
	this->worldMatrix = Matrix4::Translation(Vector3(size * gridX, 0.0f, size * gridZ));
	this->texturePack = texturePack;
	this->blendMap = blendMap;

	GenerateModel();
}

Terrain::~Terrain() {
}

void Terrain::GenerateModel() {
	std::vector<Vector4> vertices;
	std::vector<Vector2> uvs;
	std::vector<Vector3> normals;
	std::vector<unsigned int> indices;

	float cell = size / ((float)cells - 1);
	Vector2 position(0.0f, 0.0f);
	for (int i = 0; i < cells; ++i) {
		for (int j = 0; j < cells; ++j) {
			Vector4 vertex(position.x, 0.0f, position.y);
			Vector2 uv(position.x / size, position.y / size);
			Vector3 normal(0.0f, 1.0f, 0.0f);

			vertices.push_back(vertex);
			uvs.push_back(uv);
			normals.push_back(normal);

			position.x += cell;
		}
		position.x = 0.0f;
		position.y += cell;
	}
	
	for (int i = 0; i < cells - 1; ++i) {
		for (int j = 0; j < cells - 1; ++j) {
			int bottomLeft = i * cells + j;
			int bottomRight = bottomLeft + 1;
			int topRight = bottomRight + cells;
			int topLeft = bottomLeft + cells;

			indices.push_back(bottomLeft);
			indices.push_back(bottomRight);
			indices.push_back(topRight);

			indices.push_back(bottomLeft);
			indices.push_back(topRight);
			indices.push_back(topLeft);
		}
	}

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

RawModel* Terrain::GetModel() {
	return model;
}
TerrainTexturePack* Terrain::GetTexturePack() {
	return texturePack;
}
const Matrix4& Terrain::GetWorldMatrix() const {
	return worldMatrix;
}
Texture* Terrain::GetBlendMap() {
	return blendMap;
}