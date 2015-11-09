#include "Scene.h"
#include "Segment.h"

Scene::Scene() {
	Shader* shader = new Shader("Shaders/Shader.vert", "Shaders/Shader.frag");
	Object* segment = new Segment(Vector2(0.0f, 0.0f), Vector2(0.5f, 0.5f));
	segment->SetShader(shader);
}

Scene::~Scene() {
}