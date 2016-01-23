#pragma once

#include "Math/math_3d.h"
#include <GL/freeglut.h>
#include <string>
#include <vector>

class ObjLoader {
private:
	struct PackedVertex {
		Vector4 vertex;
		Vector3 normal;
		Vector2 uv;
		PackedVertex(Vector4 vertex, Vector2 uv, Vector3 normal) {
			this->vertex = vertex, this->uv = uv, this->normal = normal;
		}
		bool operator<(const PackedVertex& other) const {
			return memcmp((void*)this, (void*)&other, sizeof(PackedVertex)) > 0;
		}
	};

private:
	static std::vector<std::string> Split(const std::string& text, const char& delim);
	static void ProcessVertex(const std::vector<std::string>& vertexData, std::vector<unsigned int>& indices,
		std::vector<Vector2>& tempUVs, std::vector<Vector3>& tempNormals,
		std::vector<Vector2>& uvs, std::vector<Vector3>& normals);

public:
	static bool LoadObj(const char* filename, std::vector<Vector4>& vertices, std::vector<Vector2>& uvs, std::vector<Vector3>& normals, std::vector<unsigned int>& indices);
	static bool LoadObj2(const char* filename, std::vector<Vector4>& vertices, std::vector<Vector2>& uvs, std::vector<Vector3>& normals, std::vector<unsigned int>& indices);
};