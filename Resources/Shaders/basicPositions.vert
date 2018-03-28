#version 400 core

layout(location = 0) in vec4 vertexPos;

uniform mat4 mvp;

out VertexData
{
	vec3 color;
	vec2 uv;
} outData;

void main()
{
	gl_Position = mvp * vec4(vertexPos.xyz, 1);
}