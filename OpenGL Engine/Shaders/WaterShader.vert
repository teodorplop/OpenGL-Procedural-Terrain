#version 400

uniform mat4 gWorld;
uniform mat4 gProj;
uniform mat4 gCamera;

layout (location = 0) in vec2 inPosition;
layout (location = 1) in vec2 inTextureCoord;
layout (location = 2) in vec3 inNormal;

out DATA {
	vec3 worldPosition;
	vec2 textureCoord;
	vec3 normal;
	float visibility;
} Out;

void main() {
	mat4 gViewCamera = inverse(gCamera);
	gl_Position = gProj * gViewCamera * gWorld * vec4(inPosition.x, 0.0, inPosition.y, 1.0);

	Out.textureCoord = vec2(inPosition.x / 2.0 + 0.5, inPosition.y / 2.0 + 0.5); 
}