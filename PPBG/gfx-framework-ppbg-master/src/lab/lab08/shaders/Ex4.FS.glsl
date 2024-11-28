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
    vec4 color = texture2D(texture_1, texture_coord);

    if(color.a < 0.4) {
        discard;
    }
    out_color = color;
}
