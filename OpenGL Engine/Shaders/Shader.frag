// Fragment Shader 

#version 400

in DATA {
	vec2 textureCoord;
	vec3 normal;
} In;

struct DirectionalLight {
	vec3 color;
	float ambientIntensity;
	vec3 direction;
	float diffuseIntensity;
};

uniform DirectionalLight directionalLight;
uniform sampler2D textureSampler;

out vec4 outColor;

void main() {
	vec4 ambientColor = vec4(directionalLight.color, 1.0f) 
										* directionalLight.ambientIntensity;

	float diffuseFactor = dot(normalize(In.normal), -directionalLight.direction);

	vec4 diffuseColor;
	if (diffuseFactor > 0) {
		diffuseColor = vec4(directionalLight.color, 1.0f)
                 * directionalLight.diffuseIntensity
                 * diffuseFactor;
	} else {
		diffuseColor = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	}

	outColor = texture(textureSampler, In.textureCoord)
					 * (ambientColor + diffuseColor);
}