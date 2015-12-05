// Vertex Shader

#version 430

uniform mat4 gWorld;

layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec4 inColor;

out DATA {
	vec4 color;
} Out;

void main() {
  gl_Position = gWorld * inPosition;
	Out.color = inColor;
}