#version 420 core

uniform vec4 albedo;

uniform sampler2D albedoMap;

in VertexData
{
	vec3 color;
	vec3 normal;
	vec2 uv;
} inData;

void main()
{
    gl_FragColor = texture(albedoMap, inData.uv);
}