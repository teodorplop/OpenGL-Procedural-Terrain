#include "TerrainSettings.h"
#include "..\Utils\FileUtils.h"
#include "..\Utils\StringUtils.h"
#include "..\Utils\MyMutex.h"
#include "../Core/TimeFrame.h"

char* TerrainSettings::filePath = "terrainSettings.txt";

TerrainSettings::TerrainSettings(Scene* scene) {
	myMutex.lock();
	FileUtils::ClearFileContent(filePath);
	myMutex.unlock();

	this->scene = scene;
	this->timer = 0.0f;
}

void TerrainSettings::Update() {
	timer += TimeFrame::deltaTime;
	if (timer >= 1.0f) {
		timer = 0.0f;

		myMutex.lock();
		std::string fileContent = FileUtils::GetFileContents(filePath);
		myMutex.unlock();

		ProcessContent(fileContent);
	}
}

void TerrainSettings::ProcessContent(const std::string& content) {
	if (content.size() >= 8 && content.substr(0, 8) == "set_seed") {
		try {
			int value = std::stoi(content.substr(9));
			scene->SetSeed(value);
		} catch (std::invalid_argument) {
			printf("Invalid argument.\n");
		}
	} else if (content.size() >= 16 && content.substr(0, 16) == "set_heightMapRes") {
		try {
			int value = std::stoi(content.substr(17));
			scene->SetHeightMapRes(value);
		} catch (std::invalid_argument) {
			printf("Invalid argument.\n");
		}
	} else if (content.size() >= 11 && content.substr(0, 11) == "set_octaves") {
		try {
			int value = std::stoi(content.substr(12));
			scene->SetOctaves(value);
		} catch (std::invalid_argument) {
			printf("Invalid argument.\n");
		}
	} else if (content.size() >= 15 && content.substr(0, 15) == "set_terrainSize") {
		try {
			float value = std::stof(content.substr(16));
			scene->SetTerrainSize(value);
		} catch (std::invalid_argument) {
			printf("Invalid argument.\n");
		}
	} else if (content.size() >= 13 && content.substr(0, 13) == "set_amplitude") {
		try {
			float value = std::stof(content.substr(14));
			scene->SetTerrainHeight(value);
		} catch (std::invalid_argument) {
			printf("Invalid argument.\n");
		}
	} else if (content.size() >= 9 && content.substr(0, 9) == "set_water") {
		if (content.substr(10) == "on\n") {
			scene->SetWater(true);
		} else if (content.substr(10) == "off\n") {
			scene->SetWater(false);
		} else {
			printf("Invalid argument.\n");
		}
	} else if (content.size() >= 10 && content.substr(0, 10) == "set_smooth") {
		try {
			float value = std::stof(content.substr(11));
			scene->SetSmooth(value);
		} catch (std::invalid_argument) {
			printf("Invalid argument.\n");
		}
	} else if (content.size() >= 15 && content.substr(0, 15) == "set_persistence") {
		try {
			int value = std::stoi(content.substr(16));
			scene->SetPersistence(value);
		} catch (std::invalid_argument) {
			printf("Invalid argument.\n");
		}
	}
}