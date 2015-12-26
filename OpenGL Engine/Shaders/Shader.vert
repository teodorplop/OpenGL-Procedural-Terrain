// Vertex Shader

#version 400

uniform mat4 gWorld;
uniform mat4 gProj;
uniform mat4 gCamera;

layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec4 inColor;

out DATA {
	vec4 color;
} Out;

void main() {
  gl_Position = gProj * gCamera * gWorld * inPosition;
	Out.color = inColor;
}