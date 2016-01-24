// Vertex Shader

#version 400

uniform mat4 gWorld;
uniform mat4 gProj;
uniform mat4 gCamera;

layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec2 inTextureCoord;
layout (location = 2) in vec3 inNormal;

out DATA {
	vec2 textureCoord;
	vec3 normal;
	vec3 toCamera;
} Out;

void main() {
  gl_Position = gProj * inverse(gCamera) * gWorld * inPosition;

	Out.textureCoord = inTextureCoord * 40.0f;
	Out.normal = (gWorld * vec4(inNormal, 0.0f)).xyz;
	Out.toCamera = (gCamera * vec4(0.0f, 0.0f, 0.0f, 1.0f)).xyz - (gWorld * inPosition).xyz;
}