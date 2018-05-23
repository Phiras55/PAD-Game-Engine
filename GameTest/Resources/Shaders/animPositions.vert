#version 420 core

layout(location = 0) in vec4 vertexPos;
layout(location = 3) in vec3 vertexNormal;
layout(location = 2) in vec2 vertexUV;
layout(location = 4) in vec4 vertexBoneWeight;
layout(location = 5) in vec4 vertexBoneIndex;

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

layout (std140, binding = 1) uniform Lights
{
							// Base Alignment  	// Aligned Offset
	vec4 position;			// 16				// 0
	vec3 direction; 		// 16				// 16
} lights;

layout (std140, binding = 2, row_major) uniform Skinning
{
	mat4 mats[150];
} skinning;

////////////////////////////////////
//            Uniforms            //
////////////////////////////////////
uniform mat4 model;

////////////////////////////////////
//        Interface Blocks        //
////////////////////////////////////
out VertexData
{
	vec3 normal;
	vec2 uv;
} outData;

out FragmentInformations
{
	vec3 fragPos;
} outInfos;

void main()
{
//	vec4 pos =  		(vertexBoneWeight.x * (skinningMatrices[int(vertexBoneIndex.x)] * vertexPos)) +
//						(vertexBoneWeight.y * (skinningMatrices[int(vertexBoneIndex.y)] * vertexPos)) +
//						(vertexBoneWeight.z * (skinningMatrices[int(vertexBoneIndex.z)] * vertexPos)) +
//						(vertexBoneWeight.w * (skinningMatrices[int(vertexBoneIndex.w)] * vertexPos));

	vec4 pos = skinning.mats[1] * vertexPos;
	
	outData.normal 		= vertexNormal;
	outData.uv 			= vertexUV;
	outInfos.fragPos 	= vec3(model * vertexPos);

	gl_Position 		= camera.viewPerspective * model * vec4(pos.xyz, 1.f);
}