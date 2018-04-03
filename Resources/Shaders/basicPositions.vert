#version 400 core

layout(location = 0) in vec4 vertexPos;

uniform mat4 mvp;

layout (std140) uniform shaderData
{
	vec4 cameraPosition;
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