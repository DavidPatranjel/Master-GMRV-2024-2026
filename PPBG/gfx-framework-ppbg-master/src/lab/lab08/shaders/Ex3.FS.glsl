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
    // TODO(student): Calculate the out_color using the texture() function.

    // TODO(student): Use the "discard" directive to terminate execution
    // based on the value of the alpha channel
    vec4 color1 = texture2D(texture_1, texture_coord);
    vec4 color2 = texture2D(texture_2, texture_coord);
    vec4 color = mix(color1, color2, 0.5f);

    if(color.a < 0.4) {
        discard;
    }
    out_color = color;
}
