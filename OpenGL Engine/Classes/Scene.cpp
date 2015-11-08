#include "Scene.h"
#include "Segment.h"

Scene::Scene() {
	Object* segment = new Segment(Vector2(0.0f, 0.0f), Vector2(0.5f, 0.5f));
	segment->SetShader("Shaders/Shader.vert", "Shaders/Shader.frag");
}

Scene::~Scene() {
}