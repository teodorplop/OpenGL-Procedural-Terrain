// Fragment Shader 

#version 400

in DATA {
	vec2 textureCoord;
	vec3 normal;
	vec3 toCamera;
	float visibility;
} In;

struct DirectionalLight {
	vec3 color;
	float ambientIntensity;
	vec3 direction;
	float diffuseIntensity;
};

struct SpecularLight {
  float shineDamper;
	float reflectivity;
};

uniform vec3 skyColor;
uniform DirectionalLight directionalLight;
uniform SpecularLight specularLight;
uniform sampler2D textureSampler;

out vec4 outColor;

vec4 CalculateAmbientColor() {
	vec4 ambientColor = vec4(directionalLight.color, 1.0f) 
										* directionalLight.ambientIntensity;

	return ambientColor;
}
vec4 CalculateDiffuseColor() {
	float diffuseFactor = dot(normalize(In.normal), -directionalLight.direction);
	diffuseFactor = max(0.0f, diffuseFactor);
	vec4 diffuseColor = vec4(directionalLight.color, 1.0f)
                    * directionalLight.diffuseIntensity
                    * diffuseFactor;

	return diffuseColor;
}
vec4 CalculateSpecularColor() {
	vec3 reflectedLight = reflect(directionalLight.direction, In.normal);
	float specularFactor = dot(normalize(In.toCamera), reflectedLight);
	specularFactor = max(specularFactor, 0.0f);
	float dampedFactor = pow(specularFactor, specularLight.shineDamper);
	vec4 specularColor = vec4(dampedFactor * directionalLight.color, 1.0f);

	return specularColor;
}

void main() {
  vec4 ambientColor = CalculateAmbientColor();
	vec4 diffuseColor = CalculateDiffuseColor();
	vec4 specularColor = CalculateSpecularColor();

	vec4 textureColor = texture(textureSampler, In.textureCoord);

	outColor = textureColor * (ambientColor + diffuseColor) + specularColor;
	outColor = mix(vec4(skyColor, 1.0f), outColor, In.visibility);
}