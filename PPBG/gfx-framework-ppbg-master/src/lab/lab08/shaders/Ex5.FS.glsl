#version 330

// Input
in vec2 texture_coord;

// Uniform properties
uniform sampler2D texture_1;
uniform sampler2D texture_2;
// TODO(student): Declare various other uniforms
uniform float Time;

// Output
layout(location = 0) out vec4 out_color;


void main()
{
    vec2 new_text_coord = texture_coord;
    new_text_coord.x = mod(Time * 0.01f, 1.0f);
    vec4 color = texture2D(texture_1, new_text_coord);

    if(color.a < 0.4) {
        discard;
    }
    out_color = color;
}
