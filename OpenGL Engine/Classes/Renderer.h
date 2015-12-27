#pragma once

#include "Renderable.h"
#include <unordered_set>

class Renderer {
private:
	static Renderer* instance;

	std::unordered_set<Renderable*> objects;

public:
	static void Start();
	static void Draw();
	static void RegisterObject(Renderable* object);
	static void UnregisterObject(Renderable* object);
};
