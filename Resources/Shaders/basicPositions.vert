#version 420 core

layout(location = 0) in vec4 vertexPos;
layout(location = 2) in vec2 vertexUV;
layout(location = 3) in vec3 vertexNormal;

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
	// Data needed for fragment shader
	outData.normal 		= vertexNormal;
	outData.uv 			= vertexUV;
	outInfos.fragPos 	= vec3(model * vertexPos);
	
	// Vertex final position
	gl_Position 		= camera.viewPerspective * model * vertexPos;
}