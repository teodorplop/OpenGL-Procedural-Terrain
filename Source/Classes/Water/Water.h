#pragma once

#include "../RawModel.h"
#include "../Texture.h"
#include "../Utils/Math/Matrix4.h"

class Water {
private:
	float x, z;

	Matrix4 worldMatrix;
	RawModel* model;
public:
	Water(int gridX, int gridZ, float height = 0.0f);
	~Water();

	void SetHeight(float height);

	RawModel* GetModel();
	const Matrix4& GetWorldMatrix() const;
};