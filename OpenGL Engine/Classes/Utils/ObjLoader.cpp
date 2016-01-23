#include "ObjLoader.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

bool ObjLoader::LoadObj(const char* filename, std::vector<Vector4>& vertices, std::vector<Vector2>& uvs, std::vector<Vector3>& normals, std::vector<unsigned int>& indices) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		fprintf(stderr, "Cannot open file %s", filename);
		return false;
	}

	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	std::vector<Vector4> tempVertices;
	std::vector<Vector3> tempNormals;
	std::vector<Vector2> tempUVs;

	char lineHeader[128], emptyLine[1024];
	while (fscanf(file, "%s", lineHeader) != EOF) {
		if (strcmp(lineHeader, "v") == 0) {
			Vector4 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);

			tempVertices.push_back(vertex);
		} else if (strcmp(lineHeader, "vt") == 0) {
			Vector2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);

			tempUVs.push_back(uv);
		} else if (strcmp(lineHeader, "vn") == 0) {
			Vector3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);

			tempNormals.push_back(normal);
		} else if (strcmp(lineHeader, "f") == 0) {
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int read = fscanf(file, "%u/%u/%u %u/%u/%u %u/%u/%u\n", 
				&vertexIndex[0], &uvIndex[0], &normalIndex[0],
				&vertexIndex[1], &uvIndex[1], &normalIndex[1],
				&vertexIndex[2], &uvIndex[2], &normalIndex[2]);

			if (read != 9) {
				fprintf(stderr, "Could not parse file\n");
				return false;
			}

			for (int i = 0; i < 3; ++i) {
				vertexIndices.push_back(vertexIndex[i]);
				uvIndices.push_back(uvIndex[i]);
				normalIndices.push_back(normalIndex[i]);
			}
		} else {
			fgets(emptyLine, 1024, file);
		}
	}

	std::map<PackedVertex, unsigned int> myMap;
	for (unsigned int i = 0; i < vertexIndices.size(); ++i) {
		Vector4 vertex = tempVertices[vertexIndices[i] - 1];
		Vector2 uv = tempUVs[uvIndices[i] - 1];
		Vector3 normal = tempNormals[normalIndices[i] - 1];
		PackedVertex packedVertex(vertex, uv, normal);

		std::map<PackedVertex, unsigned int>::iterator it = myMap.find(packedVertex);
		if (it != myMap.end()) {
			indices.push_back(it->second);
		} else {
			vertices.push_back(vertex);
			uvs.push_back(uv);
			normals.push_back(normal);

			unsigned int newIndex = (unsigned int)vertices.size() - 1;
			indices.push_back(newIndex);
			myMap[packedVertex] = newIndex;
		}
	}

	return true;
}

bool ObjLoader::LoadObj2(const char* filename, std::vector<Vector4>& vertices, std::vector<Vector2>& uvs, std::vector<Vector3>& normals, std::vector<unsigned int>& indices) {
	std::vector<Vector2> tempUVs;
	std::vector<Vector3> tempNormals;

	std::ifstream file(filename);
	std::string line;
	while (std::getline(file, line)) {
		std::vector<std::string> currentLine = Split(line, ' ');

		if (line.substr(0, 2) == "v ") {
			Vector4 vertex;
			vertex.x = std::stof(currentLine[1]);
			vertex.y = std::stof(currentLine[2]);
			vertex.z = std::stof(currentLine[3]);
			vertices.push_back(vertex);
		} else if (line.substr(0, 2) == "vt") {
			Vector2 uv;
			uv.x = std::stof(currentLine[1]);
			uv.y = std::stof(currentLine[2]);
			tempUVs.push_back(uv);
		}	else if (line.substr(0, 2) == "vn") {
			Vector3 normal;
			normal.x = std::stof(currentLine[1]);
			normal.x = std::stof(currentLine[2]);
			normal.x = std::stof(currentLine[3]);
			tempNormals.push_back(normal);
		} else if (line.substr(0, 2) == "f ") {
			uvs.resize(vertices.size());
			normals.resize(vertices.size());

			std::vector<std::string> currentLine = Split(line, ' ');
			std::vector<std::string> vertex0 = Split(currentLine[1], '/');
			std::vector<std::string> vertex1 = Split(currentLine[2], '/');
			std::vector<std::string> vertex2 = Split(currentLine[3], '/');
			ProcessVertex(vertex0, indices, tempUVs, tempNormals, uvs, normals);
			ProcessVertex(vertex1, indices, tempUVs, tempNormals, uvs, normals);
			ProcessVertex(vertex2, indices, tempUVs, tempNormals, uvs, normals);

			break;
		}
	}
	while (std::getline(file, line)) {
		if (line.substr(0, 2) != "f ") {
			std::getline(file, line);
			continue;
		}

		std::vector<std::string> currentLine = Split(line, ' ');
		std::vector<std::string> vertex0 = Split(currentLine[1], '/');
		std::vector<std::string> vertex1 = Split(currentLine[2], '/');
		std::vector<std::string> vertex2 = Split(currentLine[3], '/');

		ProcessVertex(vertex0, indices, tempUVs, tempNormals, uvs, normals);
		ProcessVertex(vertex1, indices, tempUVs, tempNormals, uvs, normals);
		ProcessVertex(vertex2, indices, tempUVs, tempNormals, uvs, normals);
	}

	return true;
}

void ObjLoader::ProcessVertex(const std::vector<std::string>& vertexData, std::vector<unsigned int>& indices, std::vector<Vector2>& tempUVs, std::vector<Vector3>& tempNormals,
	std::vector<Vector2>& uvs, std::vector<Vector3>& normals) {
	int currentVertexPointer = std::stoi(vertexData[0]) - 1;
	indices.push_back(currentVertexPointer);
	uvs[currentVertexPointer] = tempUVs[std::stoi(vertexData[1]) - 1];
	uvs[currentVertexPointer].y = 1 - uvs[currentVertexPointer].y;
	normals[currentVertexPointer] = tempNormals[std::stoi(vertexData[2]) - 1];
}

std::vector<std::string> ObjLoader::Split(const std::string& text, const char& delim) {
	std::vector<std::string> elements;

	std::stringstream textStream(text);
	std::string word;
	while (std::getline(textStream, word, delim)) {
		elements.push_back(word);
	}

	return elements;
}