// Fragment Shader 

#version 400

in DATA {
	vec4 color;
} In;

out vec4 outColor;

void main() {
	outColor = In.color;
}