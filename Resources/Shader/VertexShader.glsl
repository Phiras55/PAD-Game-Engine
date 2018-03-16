#version 330 core

layout(location = 0) in vec4 vertexPos;
layout(location = 1) in vec4 vertexNormal;
layout (location = 2) in vec2 vertexUv;

uniform mat4 MVP;
uniform mat4 ModelMatrix;

out vec3 fragNormal;
out vec3 fragPos;
out vec2 uv;

void main()
{
	gl_Position 	= vec4(vertexPos.xyz, 1);
}