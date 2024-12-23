#version 330

// Input
in vec2 texture_coord;

// Uniform properties
uniform sampler2D texture_1;
uniform sampler2D texture_2;
uniform sampler2D texture_3;
uniform sampler2D texture_4;

// Output
layout(location = 0) out vec4 out_color;

void main()
{
    vec4 color1 = texture2D(texture_1, texture_coord);
	vec4 color2 = texture2D(texture_2, texture_coord);
	vec4 color3 = texture2D(texture_3, texture_coord);
	vec4 noise_map = texture2D(texture_4, texture_coord);
	color = mix(color, noise_map, 0.5f);
    if(color.a < 0.4) {
        discard;
    }
    out_color = color;
}
