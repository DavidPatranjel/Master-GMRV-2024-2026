#version 430

// Input and output topologies
layout(triangles) in;
layout(triangle_strip, max_vertices = 170) out;

// Input
layout(location = 1) in vec2 v_texture_coord[];

// Uniform properties
uniform mat4 View;
uniform mat4 Projection;
// TODO(student): Declare other uniforms here
uniform float Time;
// Output
layout(location = 0) out vec2 texture_coord;

vec3 ComputeNormal(vec4 A, vec4 B, vec4 C)
{
    vec3 edge1 = vec3(B) - vec3(A);
    vec3 edge2 = vec3(C) - vec3(A);    
    return normalize(cross(edge1, edge2));
}

void EmitVertexWithOffset(vec4 position, vec4 normal, vec2 tex_coord)
{
	float time = mod(Time, 2);
    vec4 offset = normal *  time; 
    vec4 new_position = position + offset;

    gl_Position = Projection * View * new_position; 
    texture_coord = tex_coord; 
    EmitVertex();
}


void main()
{
	// TODO(student): Emit the vertices of the triangle for which
	// information is received in the input attributes. Set the
	// following information for each vertex:
	//   - The coordinate of the vertex in clip space, transformed
	//     from world space, as received from the vertex shader
	//   - Texture coordinate received from the vertex shader.
	vec4 normal_v = vec4(ComputeNormal(gl_in[0].gl_Position, gl_in[1].gl_Position, gl_in[2].gl_Position), 0.0);
	EmitVertexWithOffset(gl_in[0].gl_Position, normal_v, v_texture_coord[0]);
	EmitVertexWithOffset(gl_in[1].gl_Position, normal_v, v_texture_coord[1]);
	EmitVertexWithOffset(gl_in[2].gl_Position, normal_v, v_texture_coord[2]);
	// End the primitive
	EndPrimitive();
	
}