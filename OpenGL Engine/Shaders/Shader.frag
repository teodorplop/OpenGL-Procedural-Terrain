// Fragment Shader 

#version 430

in DATA {
	vec4 color;
} In;

out vec4 outColor;

void main() {
	outColor = In.color;
}