#include "Renderer.h"

Renderer* Renderer::instance = NULL;

Renderer* Renderer::GetInstance() {
	if (instance == NULL) {
		instance = new Renderer();
	}
	return instance;
}

void Renderer::RegisterObject(RawModel* obj) {
	objects.insert(obj);
}
void Renderer::UnregisterObject(RawModel* obj) {
	objects.erase(obj);
}

void Renderer::Draw() {
	for (auto obj : objects) {
		obj->Draw();
	}
}