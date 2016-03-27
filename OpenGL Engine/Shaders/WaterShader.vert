#version 400

uniform mat4 gWorld;
uniform mat4 gProj;
uniform mat4 gCamera;

layout (location = 0) in vec2 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 uvs;

out DATA {
	vec4 worldPosition;
	vec3 normal;
	float visibility;
	vec2 textureCoord;
} Out;

const float tiling = 6.0;

void main() {
	mat4 gViewCamera = inverse(gCamera);

	Out.worldPosition = gProj * gViewCamera * gWorld * vec4(inPosition.x, 0.0, inPosition.y, 1.0);
	Out.textureCoord = uvs * tiling;
	//Out.textureCoord = vec2(inPosition.x / 2.0 + 0.5, inPosition.y / 2.0 + 0.5) * tiling;

	gl_Position = Out.worldPosition;
}