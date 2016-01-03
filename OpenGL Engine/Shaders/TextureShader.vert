// Vertex Shader

#version 400

uniform mat4 gWorld;
uniform mat4 gProj;
uniform mat4 gCamera;

layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec4 inColor;
layout (location = 2) in vec2 inTextureCoord;

out DATA {
	vec4 color;
	vec2 textureCoord;
} Out;

void main() {
  gl_Position = gProj * inverse(gCamera) * gWorld * inPosition;

	Out.color = inColor;
	Out.textureCoord = inTextureCoord;
}