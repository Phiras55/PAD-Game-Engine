#version 420 core

uniform vec4  albedo;
uniform vec3  ambient;
uniform vec3  diffuse;
uniform vec3  specular;
uniform float shininess;

uniform sampler2D albedoMap;

layout (std140, binding = 1) uniform DirectionalLight
{
							// Base Alignment  	// Aligned Offset
	vec3  direction;		// 16				// 0
	vec3  color;  			// 16				// 16
	float intensity;		// 4				// 32
} dLight;

in VertexData
{
	vec3 color;
	vec3 normal;
	vec2 uv;
} inData;

in vec3 cameraPos;
in vec3 cameraDir;
in vec3 fragPos;

void main()
{
	// Ambient
	float ambientIntensity 	= 0.2;
	vec3 resultAmbient 		= (ambient * ambientIntensity) * (dLight.color * dLight.intensity);
	
	// Diffuse
	vec3 normalizedNormal 	= normalize(inData.normal);
	float diff 				= max(dot(normalizedNormal, lightDir), 0.0);
	vec3 resultDiffuse 		= diff * dLight.color;
	
	// Specular
	float specularStrength 	= 0.5;
	vec3 viewDir 			= normalize(cameraPos - fragPos);
	vec3 reflectDir 		= reflect(-dLight.direction, normalizedNormal);
	float spec 				= pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 resultSpecular 	= specular * dLight.color * specularStrength * spec;
	
	// Result
	vec3 objectColor 		= texture(albedoMap, inData.uv) * albedo;
	vec3 resultLighting 	= (resultAmbient + resultDiffuse + resultSpecular) * objectColor;
	
    gl_FragColor 			= texture(albedoMap, inData.uv) * albedo;
}