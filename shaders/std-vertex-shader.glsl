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

float getRandom(vec4 pos)
{
	float val = fract(sin(dot(pos, vec4(3.1415, 12.9898, 78.233, 5.327)))* 43758.5453);
	return val;
}

float getNoise(vec4 pos, float octave)
{
	pos *= pow(2.0, octave);
	vec3 mpos = mod(pos.xyz, 1.0);
	pos = floor(pos);

	float c000 = getRandom(pos + vec4(0.0, 0.0, 0.0, 0.0));
	float c100 = getRandom(pos + vec4(1.0, 0.0, 0.0, 0.0));
	float c010 = getRandom(pos + vec4(0.0, 1.0, 0.0, 0.0));
	float c110 = getRandom(pos + vec4(1.0, 1.0, 0.0, 0.0));

	float c001 = getRandom(pos + vec4(0.0, 0.0, 1.0, 0.0));
	float c101 = getRandom(pos + vec4(1.0, 0.0, 1.0, 0.0));
	float c011 = getRandom(pos + vec4(0.0, 1.0, 1.0, 0.0));
	float c111 = getRandom(pos + vec4(1.0, 1.0, 1.0, 0.0));

	float eX00 = mix(c000, c100, mpos.x);
	float eX10 = mix(c010, c110, mpos.x);
	float eX01 = mix(c001, c101, mpos.x);
	float eX11 = mix(c011, c111, mpos.x);

	float fXX0 = mix(eX00, eX10, mpos.y);
	float fXX1 = mix(eX01, eX11, mpos.y);

	float value = mix(fXX0, fXX1, mpos.z);

	return 2.0 * (value - 0.5);
}

float getPerlin(vec4 pos, float initial, float octaves, float skip)
{
	float val = 0.0;

	for (float x = initial; x < initial + octaves; x += skip)
		val += getNoise(pos, x + 2.0) / pow(2.0, x - initial);

	return val;
}

void main()
{
	float p1 = getPerlin(vec4(VERTEX_POS, 0.0), 1.0, 1.0, 1.0);
	float p2 = getPerlin(vec4(VERTEX_POS, 1.0), 1.0, 1.0, 1.0);
	float p3 = getPerlin(vec4(VERTEX_POS, 2.0), 1.0, 1.0, 1.0);
	//Find the final position of the vertex. It's a position, so w is 1.
	gl_Position = PERSPECTIVE_MATRIX * CAMERA_MATRIX * MODEL_MATRIX * (vec4(VERTEX_POS, 1.0) + vec4(p1, p2, p3, 0.0) * 0.2);
	FRAG_POS    = CAMERA_MATRIX * MODEL_MATRIX * vec4(VERTEX_POS, 1.0);

	FRAG_M_POS = vec4(VERTEX_POS, 1.0);
	FRAG_NORM   = vec4(VERTEX_NORM, 0.0);
	FRAG_COL    = VERTEX_COL;
	FRAG_UV     = VERTEX_UV;
}
