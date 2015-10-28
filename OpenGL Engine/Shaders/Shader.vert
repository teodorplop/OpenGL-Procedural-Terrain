// Vertex Shader

#version 450

uniform float gScale;
layout (location = 0) in vec4 inPosition;

void main() {
  gl_Position = vec4(gScale * inPosition.x, gScale * inPosition.y, inPosition.z, 1.0);
}
