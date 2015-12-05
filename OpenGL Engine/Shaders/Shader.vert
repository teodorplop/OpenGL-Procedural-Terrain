// Vertex Shader

#version 430

uniform mat4 gWorld;

in vec3 inPosition;

void main() {
  gl_Position = gWorld * vec4(inPosition, 1.0);
  //gl_Position = vec4(inPosition, 1.0);
}
