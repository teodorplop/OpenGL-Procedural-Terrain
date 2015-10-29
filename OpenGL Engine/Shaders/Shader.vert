// Vertex Shader

#version 450

uniform float gScale;
uniform mat4 gWorld;
layout (location = 0) in vec3 inPosition;

void main() {
  gl_Position = gWorld * vec4(inPosition, 1.0);
  //gl_Position = vec4(gScale * inPosition.x, gScale * inPosition.y, inPosition.z, 1.0);
}
