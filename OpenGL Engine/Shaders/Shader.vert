// Vertex Shader

#version 450

uniform float gScale;
uniform mat4 gWorld;

layout (location = 0) in vec3 inPosition;
out vec4 color;

void main() {
  gl_Position = gWorld * vec4(inPosition, 1.0);
  color = vec4(clamp(inPosition, 0.0, 1.0), 1.0);
}
