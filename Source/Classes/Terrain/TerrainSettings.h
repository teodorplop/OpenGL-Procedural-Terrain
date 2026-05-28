#pragma once

#include<string>
#include "../Scene.h"

class TerrainSettings {
public:
	static char* filePath;
	TerrainSettings(Scene* scene);
	void Update();

private:
	void ProcessContent(const std::string& content);

	Scene* scene;
	float timer;
};

