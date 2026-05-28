#version 400

in DATA {
	vec4 worldPosition;
	vec3 normal;
	vec2 textureCoord;
	vec3 toCamera;
} In;

uniform sampler2D reflectionSampler;
uniform sampler2D refractionSampler;
uniform sampler2D dudvSampler;
uniform float moveFactor;

const float distortionStrength = 0.02;

out vec4 outColor;

void main() {
	vec2 normalizedDeviceCoord = (In.worldPosition.xy / In.worldPosition.w) / 2.0 + 0.5;
	vec2 reflectionTextureCoord = vec2(normalizedDeviceCoord.x, -normalizedDeviceCoord.y);
	vec2 refractionTextureCoord = vec2(normalizedDeviceCoord.x, normalizedDeviceCoord.y);

	vec2 distortion1 = (texture(dudvSampler, vec2(In.textureCoord.x + moveFactor, In.textureCoord.y)).rg * 2.0 - 1.0) * distortionStrength;
	vec2 distortion2 = (texture(dudvSampler, vec2(-In.textureCoord.x + moveFactor, In.textureCoord.y + moveFactor)).rg * 2.0 - 1.0) * distortionStrength;
	vec2 totalDistortion = distortion1 + distortion2;

	reflectionTextureCoord += totalDistortion;
	//reflectionTextureCoord.x = clamp(reflectionTextureCoord.x, 0.001, 0.999);
	//reflectionTextureCoord.y = clamp(reflectionTextureCoord.y, -0.001, -0.999);

	refractionTextureCoord += totalDistortion;
	refractionTextureCoord = clamp(refractionTextureCoord, 0.001, 0.999);

	vec4 reflectionColor = texture(reflectionSampler, reflectionTextureCoord);
	vec4 refractionColor = texture(refractionSampler, refractionTextureCoord);

	vec3 viewVector = normalize(In.toCamera);
	float refractiveFactor = dot(viewVector, In.normal);
	refractiveFactor = pow(refractiveFactor, 0.1);

	outColor = mix(reflectionColor, refractionColor, refractiveFactor);
	outColor = mix(outColor, vec4(0.0, 0.3, 0.5, 1.0f), 0.2);
}