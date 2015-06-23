#version 130

smooth in vec2 UV;

out vec3 COLOUR;

uniform sampler2D RENDER_TEXTURE;

void main()
{
	COLOUR = texture(RENDER_TEXTURE, (vec2(1.0, 1.0) + UV) / 2.0).xyz;
	//COLOUR = vec3(1.0, 1.0, 0.0);
}
