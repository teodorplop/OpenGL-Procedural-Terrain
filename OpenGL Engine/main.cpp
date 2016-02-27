#include "Classes\Core\Engine.h"

#include "Classes\Terrain\HeightMapGenerator.h"
int main(int argc, char** argv) {
	HeightMapGenerator::Generate("test", 256, 256);
	Engine::Start(argc, argv);
}