#version 330

// Input
layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_texture_coord;
layout(location = 3) in vec3 v_color;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform sampler2D texture_2;


// Output
out vec2 texture_coord;

void main()
{
    texture_coord = v_texture_coord;
	vec3 v_position_nou = v_position;
	vec4 noise_map = texture2D(texture_2, texture_coord);
	v_position_nou.y += noise_map.r * 5.0;
    gl_Position = Projection * View * Model * vec4(v_position_nou, 1.0);
}
