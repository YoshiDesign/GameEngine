#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 color_u;
uniform vec2 light_pos;

in DATA
{
	vec4 position;
	vec4 color;

} fs_in;


void main()
{
	float intensity = 1.0 / length(fs_in.position.xy - light_pos);
	//color = color_u * intensity;
	color = fs_in.color * intensity;
}