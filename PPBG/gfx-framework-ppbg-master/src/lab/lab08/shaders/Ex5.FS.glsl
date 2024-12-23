#version 330

// Input
in vec2 texture_coord;

// Uniform properties
uniform sampler2D texture_1;
uniform sampler2D texture_2;

// Output
layout(location = 0) out vec4 out_color;

void main()
{
    vec4 color = texture2D(texture_1, texture_coord);
	vec4 noise_map = texture2D(texture_2, texture_coord);
	vec4 noise_map_bw = vec4(noise_map.r, noise_map.r, noise_map.r, noise_map.r);
	color = mix(color, noise_map_bw, 0.5f);
    if(color.a < 0.4) {
        discard;
    }
    out_color = color;
}
