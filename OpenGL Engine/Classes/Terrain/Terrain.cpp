#include "Terrain.h"
#include "../Buffers/VertexArray.h"
#include "../Buffers/Buffer.h"
#include "../Buffers/IndexBuffer.h"
#include <vector>

// total square size
float Terrain::size = 800.0f;
float Terrain::maxHeight = 40.0f;
float Terrain::maxPixelColor = 256.0f * 256.0f * 256.0f;

Terrain::Terrain(int gridX, int gridZ, TerrainTexturePack* texturePack, Texture* blendMap, const char* heightMap) {
	this->worldMatrix = Matrix4::Translation(Vector3(size * gridX, 0.0f, size * gridZ));
	this->texturePack = texturePack;
	this->blendMap = blendMap;

	GenerateModel(heightMap);
}

Terrain::~Terrain() {
}

void Terrain::GenerateModel(const char* heightMap) {
	int cells = 64;

	FIBITMAP* data = ImageUtils::Load_Image(heightMap);
	float** heights;
	if (data == NULL) {
		fprintf(stderr, "Could not load height map: %s\n", heightMap);
	} else {
		cells = FreeImage_GetWidth(data);

		if (cells != FreeImage_GetHeight(data)) {
			fprintf(stderr, "Height map needs to be a square texture: %s\n", heightMap);
		}
	}
	heights = new float*[cells];
	for (int i = 0; i < cells; ++i) {
		heights[i] = new float[cells];
	}
	CalculateHeights(heights, cells, data);

	std::vector<Vector4> vertices;
	std::vector<Vector2> uvs;
	std::vector<Vector3> normals;
	std::vector<unsigned int> indices;

	float cell = size / ((float)cells - 1);
	Vector2 position(0.0f, 0.0f);
	for (int i = 0; i < cells; ++i) {
		for (int j = 0; j < cells; ++j) {
			Vector4 vertex(position.x, heights[i][j], position.y);
			Vector2 uv(position.x / size, position.y / size);
			Vector3 normal = CalculateNormal(i, j, heights, cells);

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

void Terrain::CalculateHeights(float** heights, const int& cells, FIBITMAP* data) {
	for (int i = 0; i < cells; ++i) {
		for (int j = 0; j < cells; ++j) {
			heights[i][j] = data ? GetHeight(data, i, j) : 0.0f;
		}
	}
}

Vector3 Terrain::CalculateNormal(const int& x, const int &y, float** heights, const int& cells) {
	float heightLeft = x > 0 ? heights[x - 1][y] : 0.0f;
	float heightRight = x < cells - 1 ? heights[x + 1][y] : 0.0f;
	float heightUp = y < cells - 1 ? heights[x][y + 1] : 0.0f;
	float heightDown = y > 0 ? heights[x][y - 1] : 0.0f;

	return Vector3(heightLeft - heightRight, 2.0f, heightDown - heightUp).Normalize();
}

float Terrain::GetHeight(FIBITMAP* data, const int& x, const int& y) {
	RGBQUAD rgbQuad;
	if (!FreeImage_GetPixelColor(data, x, y, &rgbQuad)) {
		fprintf(stderr, "Failed to get pixel color\n");
		return 0.0f;
	}

	float pixelColor = (float)rgbQuad.rgbRed * rgbQuad.rgbGreen * rgbQuad.rgbBlue;
	pixelColor -= maxPixelColor / 2.0f;
	pixelColor /= maxPixelColor / 2.0f;

	return pixelColor * maxHeight;
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