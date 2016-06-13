#pragma once

#include "Transform.h"
#include "Utils/Math/Matrix4.h"

enum Projection {Orthographic, Perspective};

class Camera {
private:
	float aspectRatio, nearClip, farClip;
	// orthographic
	float orthographicSize;
	// perspective
	float fieldOfView;

	Projection projectionType;
	Matrix4 projectionMatrix;
	Transform* transform;

public:
	Camera(Projection projection, float size, float aspectRatio, float nearClip = 1.0f, float farClip = 100.0f);
	~Camera();
	Projection GetProjectionType();
	Matrix4 GetProjectionMatrix();
	Transform* GetTransform();

private:
	void SetOrthographic(float size, float aspectRatio, float nearClip = 1.0f, float farClip = 100.0f);
	void SetPerspective(float fieldOfView, float aspectRatio, float nearClip = 1.0f, float farClip = 100.0f);
};