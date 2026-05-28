#version 400

uniform mat4 gWorld;
uniform mat4 gProj;
uniform mat4 gCamera;

uniform vec3 cameraPosition;

layout (location = 0) in vec2 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 uvs;

out DATA {
	vec4 worldPosition;
	vec3 normal;
	vec2 textureCoord;
	vec3 toCamera;
} Out;

const float tiling = 6.0;

void main() {
	vec4 worldPosition = gWorld * vec4(inPosition.x, 0.0, inPosition.y, 1.0);
	mat4 gViewCamera = inverse(gCamera);

	Out.worldPosition = gProj * gViewCamera * worldPosition;
	Out.textureCoord = uvs * tiling;
	Out.normal = inNormal;
	Out.toCamera = cameraPosition - worldPosition.xyz;

	gl_Position = Out.worldPosition;
}