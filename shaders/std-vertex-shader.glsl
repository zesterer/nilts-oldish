#version 130

//----UNIFORMS----
uniform            mat4 PERSPECTIVE_MATRIX;
uniform            mat4 CAMERA_MATRIX;
uniform            mat4 MODEL_MATRIX;

//----INPUTS----
in         highp   vec3 VERTEX_POS;
in         lowp    vec3 VERTEX_COL;
in         mediump vec2 VERTEX_UV;
in         lowp    vec3 VERTEX_NORM;

//----OUTPUTS----
smooth out highp   vec4 FRAG_M_POS;
smooth out highp   vec4 FRAG_POS;
smooth out lowp    vec3 FRAG_COL;
smooth out mediump vec2 FRAG_UV;
smooth out lowp    vec4 FRAG_NORM;

void main()
{
	//Find the final position of the vertex. It's a position, so w is 1.
	gl_Position = PERSPECTIVE_MATRIX * CAMERA_MATRIX * MODEL_MATRIX * vec4(VERTEX_POS, 1.0);
	FRAG_POS    = CAMERA_MATRIX * MODEL_MATRIX * vec4(VERTEX_POS, 1.0);

	FRAG_M_POS = vec4(VERTEX_POS, 1.0);
	FRAG_NORM   = vec4(VERTEX_NORM, 0.0);
	FRAG_COL    = VERTEX_COL;
	FRAG_UV     = VERTEX_UV;
}
