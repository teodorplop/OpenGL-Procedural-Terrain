// Fragment Shader 

#version 400

in DATA {
  vec3 worldPosition;
	vec2 textureCoord;
	vec3 normal;
	float visibility;
} In;

struct DirectionalLight {
	vec3 color;
	float ambientIntensity;
	vec3 direction;
	float diffuseIntensity;
};

struct SpecularLight {
  float materialIntensity;
	float power;
};

uniform vec3 skyColor;
uniform DirectionalLight directionalLight;

uniform vec3 eyeWorldPosition;
uniform SpecularLight specularLight;

uniform sampler2D backgroundSampler;
uniform sampler2D rSampler;
uniform sampler2D gSampler;
uniform sampler2D bSampler;
uniform sampler2D blendMapSampler;

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
	vec3 vertexToEye = normalize(eyeWorldPosition - In.worldPosition);
	vec3 lightReflect = normalize(reflect(directionalLight.direction, normalize(In.normal)));
	float specularFactor = max(0.0f, dot(vertexToEye, lightReflect));
	specularFactor = pow(specularFactor, specularLight.power);
	vec4 specularColor = vec4(directionalLight.color * specularLight.materialIntensity * specularFactor, 1.0f);

	return specularColor;
}

vec4 CalculateTerrainColor() {
	vec4 blendMapColor = texture(blendMapSampler, In.textureCoord);
	float backTextureAmount = 1 - (blendMapColor.r + blendMapColor.g + blendMapColor.b);
	vec2 tiledCoordinates = In.textureCoord * 40.0f;

	vec4 backgroundTextureColor = texture(backgroundSampler, tiledCoordinates) * backTextureAmount;
	vec4 rTextureColor = texture(rSampler, tiledCoordinates) * blendMapColor.r;
	vec4 gTextureColor = texture(gSampler, tiledCoordinates) * blendMapColor.g;
	vec4 bTextureColor = texture(bSampler, tiledCoordinates) * blendMapColor.b;
	
	return backgroundTextureColor + rTextureColor + gTextureColor + bTextureColor;
}

void main() {
	vec4 totalColor = CalculateTerrainColor();

  vec4 ambientColor = CalculateAmbientColor();
	vec4 diffuseColor = CalculateDiffuseColor();
	vec4 specularColor = CalculateSpecularColor();

	outColor = totalColor * (ambientColor + diffuseColor + specularColor);
	outColor = mix(vec4(skyColor, 1.0f), outColor, In.visibility);
}