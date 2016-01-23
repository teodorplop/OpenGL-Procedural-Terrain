#pragma once

#include "../RawModel.h"
#include <unordered_set>

class Renderer {
private:
	static Renderer* instance;

	std::unordered_set<RawModel*> objects;

public:
	static Renderer* GetInstance();

	void RegisterObject(RawModel* object);
	void UnregisterObject(RawModel* object);
	void Draw();
};
