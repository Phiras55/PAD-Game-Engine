#version 330 core

struct Material 
{
		vec3 ambient;
		vec3 diffuse;
		vec3 specular;
		float shininess;
}; 

in vec3 fragNormal;
in vec3 fragPos;
in vec2 uv;

uniform vec3 lightColor;
uniform vec3 lightDir;
uniform vec3 cameraPos;
uniform sampler2D textureSampler;

uniform Material material;

out vec3 color;

void main()
{
    color 							= vec3(1, 0, 0);
}