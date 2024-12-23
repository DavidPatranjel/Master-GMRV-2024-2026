#version 330

// Input
in vec2 texture_coord;

// Uniform properties
uniform sampler2D texture_1;
uniform sampler2D texture_2;
// TODO(student): Declare various other uniforms


// Output
layout(location = 0) out vec4 out_color;


void main()
{
    vec4 color = texture(texture_1, texture_coord);

    out_color = color;
}
