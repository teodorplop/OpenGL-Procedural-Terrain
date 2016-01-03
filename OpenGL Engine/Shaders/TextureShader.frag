// Fragment Shader 

#version 400

in DATA {
	vec4 color;
	vec2 textureCoord;
} In;

uniform sampler2D gSampler;

out vec4 outColor;

void main() {
	//outColor = In.color;
	outColor = texture2D(gSampler, In.textureCoord.st) * In.color;
}