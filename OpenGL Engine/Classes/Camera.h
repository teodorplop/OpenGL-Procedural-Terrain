#pragma once

#include "Utils/Math/Matrix4.h"
#include "Transform.h"

enum Projection {Orthographic, Perspective};

class Camera {
private:
	static Camera* mainCamera;

	float nearClip, farClip;
	// orthographic
	float left, right, bottom, top;
	// perspective
	float fieldOfView, aspectRatio;

	Projection projectionType;
	Matrix4 projectionMatrix;
	Transform* transform;

	void Zoom(float value);

public:
	static Camera* GetMainCamera();

	Camera();
	~Camera();
	Projection GetProjectionType();
	Matrix4 GetProjectionMatrix();
	Transform* GetTransform();

	void ZoomIn();
	void ZoomOut();
};