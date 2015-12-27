#include "Renderer.h"
#include <iostream>

Renderer* Renderer::instance = NULL;

void Renderer::RegisterObject(Renderable* obj) {
	instance->objects.insert(obj);
}
void Renderer::UnregisterObject(Renderable* obj) {
	instance->objects.erase(obj);
}

void Renderer::Start() {
	if (instance == NULL) {
		instance = new Renderer();
	}
}

void Renderer::Draw() {
	for (auto obj : instance->objects) {
		obj->Draw();
	}
}