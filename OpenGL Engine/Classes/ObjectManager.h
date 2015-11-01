#include <vector>
#include "Object.h"

class ObjectManager {
private:
	static ObjectManager* instance;
	std::vector<Object*> objects;
public:
	static void Start();
	static void RegisterObject(Object* obj);
	static void UnregisterObject(Object* obj);
	static void Update();
};