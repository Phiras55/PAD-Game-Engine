#version 400 core

layout(location = 0) in vec4 vertexPos;

uniform mat4 model;

layout (std140, binding = 0, row_major) uniform CameraSettings
{
							// Base Alignment  	// Aligned Offset
	vec3 position;			// 16			   	// 0
	vec3 direction; 		// 16				// 16
	mat4 viewPerspective	// 64				// 32
} camera;

layout (std140, binding = 1) uniform Lights
{
							// Base Alignment  	// Aligned Offset
	vec4 position;			// 16				// 0
	vec3 direction; 		// 16				// 16
} lights;

out VertexData
{
	vec3 color;
	vec2 uv;
} outData;

void main()
{
	gl_Position = camera.viewPerspective * model * vec4(vertexPos.xyz, 1.f);
}