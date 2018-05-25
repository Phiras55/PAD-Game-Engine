#version 420 core

////////////////////////////////////
//         Uniform Blocks         //
////////////////////////////////////
layout (std140, binding = 0, row_major) uniform CameraSettings
{
							// Base Alignment  	// Aligned Offset
	vec3 position;			// 16			   	// 0
	vec3 direction; 		// 16				// 16
	mat4 viewPerspective;	// 64				// 32
} camera;

layout (std140, binding = 1) uniform DirectionalLightSettings
{
							// Base Alignment  	// Aligned Offset
	vec3  direction;		// 16				// 0
	vec3  color;  			// 16				// 16
	float intensity;		// 4				// 32
} dLight;

////////////////////////////////////
//            Uniforms            //
////////////////////////////////////
uniform vec3  ambient;
uniform vec3  tint;
uniform vec3  specular;
uniform float shininess;
uniform sampler2D albedoMap;
uniform bool isAffectedByLight = false;

////////////////////////////////////
//        Interface Blocks        //
////////////////////////////////////
in VertexData
{
	vec3 normal;
	vec2 uv;
} inData;

in FragmentInformations
{
	vec3 fragPos;
} inInfos;

out vec4 finalColor;

void main()
{
	vec4 resultLighting;
	vec4 objectColor 		= texture(albedoMap, inData.uv) * vec4(tint, 1.0);
	
	if(isAffectedByLight)
	{
		// Ambient
		float ambientIntensity 	= 0.2;
		vec3 resultAmbient 		= ambient * ambientIntensity;
		
		// Diffuse
		vec3 normalizedNormal 	= normalize(inData.normal);
		float diff 				= max(dot(normalizedNormal, -dLight.direction), 0.0);
		vec3 resultDiffuse 		= dLight.color * diff;
		
		// Specular
		float specularStrength 	= 1.0;
		vec3 viewDir 			= normalize(camera.position - inInfos.fragPos);
		vec3 reflectDir 		= reflect(-dLight.direction, normalizedNormal);
		float spec 				= pow(max(dot(viewDir, reflectDir), 0.0), shininess);
		vec3 resultSpecular 	= specular * (specularStrength * spec);
		
		// Result
		vec4 resultLighting 	= vec4(resultAmbient + resultDiffuse + resultSpecular, 1.0) * objectColor;
	}
	else
	{
		resultLighting = objectColor;
	}
	
	finalColor = resultLighting;
}