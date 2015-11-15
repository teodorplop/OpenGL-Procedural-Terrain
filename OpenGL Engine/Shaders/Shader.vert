// Vertex Shader

#version 450

uniform float gScale;
uniform mat4 gWorld;

layout (location = 0) in vec3 inPosition;

void main() {
  gl_Position = gWorld * vec4(inPosition, 1.0);
}
