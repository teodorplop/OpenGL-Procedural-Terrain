#ifndef __OBJECT_MANAGER_H__
#define __OBJECT_MANAGER_H__

#include <vector>
#include <unordered_set>
#include "Object.h"

class ObjectManager {
private:
	static ObjectManager* instance;

	std::unordered_set<Object*> objects;
public:
	static void Start();
	static void RegisterObject(Object* obj);
	static void UnregisterObject(Object* obj);

	static void Update();
	static void Draw();
	static void CleanUp();
};

#endif//__OBJECT_MANAGER_H__