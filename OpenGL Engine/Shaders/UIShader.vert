// Vertex Shader

#version 400

uniform mat4 gWorld;
uniform mat4 gProj;
uniform mat4 gCamera;

layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec2 inTextureCoord;

out DATA {
	vec3 worldPosition;
	vec2 textureCoord;
} Out;

void main() {
	gl_Position = gWorld * inPosition;

	Out.worldPosition = gl_Position.xyz;
	Out.textureCoord = inTextureCoord;
}