#version 400 core

uniform vec4 albedo;

in VertexData
{
	vec3 color;
	vec2 uv;
} inData;

void main()
{
    gl_FragColor = vec4(albedo.xyz, 1.f);
}