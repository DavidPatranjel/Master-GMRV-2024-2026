#version 430

// Input
layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_texture_coord;

// Uniform properties
uniform mat4 Model;

// Output
layout(location = 2) out vec4 normal_point;
layout(location = 1) out vec2 texture_coord;

void main()
{
    texture_coord = v_texture_coord;
    normal_point = Model * vec4(4 * v_normal + v_position, 1);

    gl_Position = Model * vec4(v_position, 1);
}
