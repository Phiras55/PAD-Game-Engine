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
	vec4 textureColor = texture(albedoMap, vec2(inData.uv.x, inData.uv.y));
    gl_FragColor = textureColor;
}