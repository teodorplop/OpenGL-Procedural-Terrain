#pragma once

#include <vector>
#include <unordered_set>
#include "../Object.h"

class ObjectManager {
private:
	static ObjectManager* instance;

	std::unordered_set<Object*> objects;

public:
	static ObjectManager* GetInstance();

	void RegisterObject(Object* obj);
	void UnregisterObject(Object* obj);
	void Update();
	void CleanUp();
};