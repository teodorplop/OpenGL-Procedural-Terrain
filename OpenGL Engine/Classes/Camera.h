#pragma once

#include "Utils/Math/Matrix4.h"
#include "Component.h"

enum Projection {Orthographic, Perspective};

class Camera : public Component {
private:
	static Camera* mainCamera;

	float aspectRatio, nearClip, farClip;
	// orthographic
	float orthographicSize;
	// perspective
	float fieldOfView;

	Projection projectionType;
	Matrix4 projectionMatrix;

public:
	static Camera* GetMainCamera();

	Camera(Projection projection, float size, float aspectRatio, float nearClip = 1.0f, float farClip = 100.0f);
	~Camera();
	Projection GetProjectionType();
	Matrix4 GetProjectionMatrix();

	void SetOrthographic(float size, float aspectRatio, float nearClip = 1.0f, float farClip = 100.0f);
	void SetPerspective(float fieldOfView, float aspectRatio, float nearClip = 1.0f, float farClip = 100.0f);
	
	void SetOrthographicSize(float size);
	void SetFieldOfView(float fieldOfView);
	float GetOrthographicSize();
	float GetFieldOfView();
};