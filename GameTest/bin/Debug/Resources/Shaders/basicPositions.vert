#version 400 core

layout(location = 0) in vec4 vertexPos;

uniform mat4 model;

layout (std140) uniform CameraSettings
{
					// Base Alignment  	// Aligned Offset
	vec3 position;	// 16			   	// 0
	vec3 direction; // 16				// 16
	mat4 mv
};

layout (std140) uniform Lights
{
					// Base Alignment  	// Aligned Offset
	vec4 position;	// 16				// 0
	vec3 direction; // 16				// 16
};

out VertexData
{
	vec3 color;
	vec2 uv;
} outData;

void main()
{
	gl_Position = mvp * vec4(vertexPos.xyz, 1.f);
}