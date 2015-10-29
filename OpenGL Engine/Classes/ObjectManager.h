#include <vector>
#include "Object.h"

class ObjectManager {
private:
	static ObjectManager* instance;
	std::vector<Object*> objects;
public:
	static void Initialize();
	void Register(Object* obj);
};