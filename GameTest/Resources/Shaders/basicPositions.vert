#version 420 core

layout(location = 0) in vec4 vertexPos;
layout(location = 3) in vec3 vertexNormal;
layout(location = 2) in vec2 vertexUv;

uniform mat4 model;

layout (std140, binding = 0, row_major) uniform CameraSettings
{
							// Base Alignment  	// Aligned Offset
	vec3 position;			// 16			   	// 0
	vec3 direction; 		// 16				// 16
	mat4 viewPerspective;	// 64				// 32
} camera;

out VertexData
{
	vec3 color;
	vec3 normal;
	vec2 uv;
} outData;

out vec3 cameraPos;
out vec3 cameraDir;
out vec3 fragPos;

void main()
{
	// Data needed for fragments
	outData.normal 	= vertexNormal;
	outData.uv 		= vertexUv;
	cameraPos 		= camera.position;
	cameraDir 		= camera.direction;
	fragPos 		= vec3(model * vertexPos);
	
	// Vertex final position
	gl_Position = camera.viewPerspective * model * vertexPos;
}