#pragma once

#include "../RawModel.h"
#include "../Texture.h"
#include "TerrainTexturePack.h"
#include "../Utils/Math/Matrix4.h"
#include "../Utils/ImageUtils.h"

class Terrain {
public:
	static float size;
	static float maxHeight;
private:
	static const float maxPixelColor;

	float x, z;
	Matrix4 worldMatrix;
	RawModel* model;
	Texture* texture;

	int cells;
	float** heights;

	void GenerateModel(const char* heightMap);
	void CalculateHeights(FIBITMAP* data);
	void SmoothHeights(float alpha);
	Vector3 CalculateNormal(const int& x, const int& y);
	float GetHeight(FIBITMAP* data, const int& x, const int& y);

public:
	Terrain(int gridX, int gridZ, Texture* texture, const char* heightMap);
	~Terrain();

	float GetTerrainHeight(const float& worldX, const float& worldZ);

	const Matrix4& GetWorldMatrix() const;
	RawModel* GetModel();
	Texture* GetTexture();
};
