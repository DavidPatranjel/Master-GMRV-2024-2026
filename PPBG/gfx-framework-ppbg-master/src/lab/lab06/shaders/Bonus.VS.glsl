#version 330

// Input
// TODO(student): Get vertex attributes from each location

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform float Time;

layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_tex_coord;
layout(location = 3) in vec3 v_color;

// Output
// TODO(student): Output values to fragment shader
out vec3 color;

void main()
{
    // TODO(student): Send output to fragment shader
	float cs = cos(Time + (v_position.x + v_position.y * 21.312 + v_position.z * 12.123) * 10) * 0.1;
    mat4 m_translate = mat4(
        vec4(1.0, 0.0, 0.0, 0.0),
        vec4(0.0, 1.0, 0.0, 0.0),
        vec4(0.0, 0.0, 1.0, 0.0),
        vec4(cs * v_normal.x, cs * v_normal.y, cs * v_normal.z, 1.0)
    );

    color = v_position;
    gl_Position = Projection * View  * Model * m_translate * vec4(v_position, 1.0);
}
