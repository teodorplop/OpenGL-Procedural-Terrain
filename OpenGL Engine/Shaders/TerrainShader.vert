// Vertex Shader

#version 400

uniform mat4 gWorld;
uniform mat4 gProj;
uniform mat4 gCamera;

layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec2 inTextureCoord;
layout (location = 2) in vec3 inNormal;

struct Fog {
  float density;
	float gradient;
};

uniform Fog fog = Fog(0.0035f, 5.0f);

out DATA {
	vec2 textureCoord;
	vec3 normal;
	vec3 toCamera;
	float visibility;
} Out;

void main() {
  vec4 worldPosition = gWorld * inPosition;
	mat4 gViewCamera = inverse(gCamera);
	vec4 positionRelativeToCamera =  gViewCamera * worldPosition;
	float distance = length(positionRelativeToCamera.xyz);

	gl_Position = gProj * positionRelativeToCamera;

	Out.textureCoord = inTextureCoord * 40.0f;
	Out.normal = (gWorld * vec4(inNormal, 0.0f)).xyz;
	Out.toCamera = (gCamera * vec4(0.0f, 0.0f, 0.0f, 1.0f)).xyz - (gWorld * inPosition).xyz;
	Out.visibility = clamp(exp(-pow(distance * fog.density, fog.gradient)), 0.0f, 1.0f);
}