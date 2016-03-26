#version 400

in DATA {
	vec3 worldPosition;
	vec2 textureCoord;
	vec3 normal;
	float visibility;
} In;

out vec4 outColor;

void main() {
	outColor = vec4(0.0, 0.0, 1.0, 1.0);
}