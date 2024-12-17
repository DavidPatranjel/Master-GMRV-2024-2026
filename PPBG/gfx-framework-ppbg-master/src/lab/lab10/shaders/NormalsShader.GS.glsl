#version 430

// Input and output topologies
layout(triangles) in;
layout(line_strip, max_vertices = 6) out;

// Input
layout(location = 1) in vec2 v_texture_coord[];
layout(location = 2) in vec4 v_normals[];
// Uniform properties
uniform mat4 View;
uniform mat4 Projection;
// TODO(student): Declare other uniforms here

// Output
layout(location = 0) out vec3 color;

void main()
{
	// TODO(student): Emit the vertices of the triangle for which
	// information is received in the input attributes. Set the
	// following information for each vertex:
	//   - The coordinate of the vertex in clip space, transformed
	//     from world space, as received from the vertex shader
	//   - Texture coordinate received from the vertex shader.


	vec4 w_pos = gl_in[0].gl_Position;
	gl_Position = Projection * View * w_pos;
	color = vec3(0.0, 0.0, 1.0);
	EmitVertex();
	gl_Position = Projection * View * v_normals[0];
	color = vec3(0.0, 0.0, 1.0);
	EmitVertex();
	EndPrimitive();
	
	w_pos = gl_in[1].gl_Position;
	gl_Position = Projection * View * w_pos;
	color = vec3(0.0, 0.0, 1.0);
	EmitVertex();
	gl_Position = Projection * View * v_normals[1];
	color = vec3(0.0, 0.0, 1.0);
	EmitVertex();
	EndPrimitive();
 

	w_pos = gl_in[2].gl_Position;
	gl_Position = Projection * View * w_pos;
	color = vec3(0.0, 0.0, 1.0);
	EmitVertex();
	gl_Position = Projection * View * v_normals[2];
	color = vec3(0.0, 0.0, 1.0);
	EmitVertex();
	EndPrimitive();
 
	
}