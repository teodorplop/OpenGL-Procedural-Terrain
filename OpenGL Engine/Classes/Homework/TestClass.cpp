#include "TestClass.h"
#include "../Utils/ObjLoader.h"
#include "../Utils/Math/math_3d.h"
#include "../GameObject.h"
#include <vector>

TestClass::TestClass() {
	std::vector<Vector4> vertices;
	std::vector<Vector3> normals;
	std::vector<Vector2> uvs;
	std::vector<unsigned int> indices;
	bool success = ObjLoader::LoadObj("Obj/stall.obj", vertices, uvs, normals, indices);
	if (success) {
		vertexArray = new VertexArray();
		Buffer* positionBuffer = new Buffer(vertices);
		Buffer* uvBuffer = new Buffer(uvs);
		Buffer* normalBuffer = new Buffer(normals);
		indexBuffer = new IndexBuffer(indices);
		vertexArray->AddBuffer(positionBuffer, 0);
		vertexArray->AddBuffer(uvBuffer, 1);
		vertexArray->AddBuffer(normalBuffer, 2);

		texture = new Texture("test3.jpg");
		shader = new Shader("Shaders/Shader.vert", "Shaders/Shader.frag");
	} else {
		SetActive(false);
	}
}

TestClass::~TestClass() {
}

void TestClass::Update() {
	gameObject->GetTransform()->RotateBy(1.0f, Vector3(1.0f, 0.0f, 0.0f));
	gameObject->GetTransform()->RotateBy(1.0f, Vector3(0.0f, 1.0f, 0.0f));
	gameObject->GetTransform()->RotateBy(1.0f, Vector3(0.0f, 0.0f, 1.0f));
}