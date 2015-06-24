#version 130

smooth in vec2 UV;

out vec3 COLOUR;

uniform sampler2D RENDER_TEXTURE;

float getRandom(vec4 pos)
{
	float val = fract(sin(dot(pos, vec4(3.1415, 12.9898, 78.233, 5.327)))* 43758.5453);
	return val;
}

float getNoise(vec4 pos, float octave)
{
	pos       *= pow(2.0, octave);
	vec3 mpos  = mod(pos.xyz, 1.0);
	pos        = floor(pos);

	float c000  = getRandom(pos + vec4(0.0, 0.0, 0.0, 0.0));
	float c100  = getRandom(pos + vec4(1.0, 0.0, 0.0, 0.0));
	float c010  = getRandom(pos + vec4(0.0, 1.0, 0.0, 0.0));
	float c110  = getRandom(pos + vec4(1.0, 1.0, 0.0, 0.0));

	float c001  = getRandom(pos + vec4(0.0, 0.0, 1.0, 0.0));
	float c101  = getRandom(pos + vec4(1.0, 0.0, 1.0, 0.0));
	float c011  = getRandom(pos + vec4(0.0, 1.0, 1.0, 0.0));
	float c111  = getRandom(pos + vec4(1.0, 1.0, 1.0, 0.0));

	float eX00  = mix(c000, c100, mpos.x);
	float eX10  = mix(c010, c110, mpos.x);
	float eX01  = mix(c001, c101, mpos.x);
	float eX11  = mix(c011, c111, mpos.x);

	float fXX0  = mix(eX00, eX10, mpos.y);
	float fXX1  = mix(eX01, eX11, mpos.y);

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

vec3 getSizeBlob()
{
	vec3 colour;
	vec2 sample_position = UV;
	float split = 8.0;

	sample_position = floor(sample_position * split) / split;

	colour = texture2D(RENDER_TEXTURE, (vec2(1.0, 1.0) + sample_position) / 2.0).rgb;
	float brightness = (colour.x + colour.y + colour.z) / 3.0;

	if (distance(floor(UV * split) / split + 0.5 / split, UV) > brightness * 0.5 / split)
		colour = vec3(0.0, 0.0, 0.0);
	else
		colour = normalize(colour);

	return colour;
}

vec3 getGaussianAt(vec2 pos, float size)
{
	vec3 sum = vec3(0.0);
	float total = 0.0;

	for (int i = -3; i < 3; i += 1)
	{
		for (int j = -3; j < 3; j += 1)
		{
			vec3 col = texture2D(RENDER_TEXTURE, pos + vec2(float(i), float(j)) / size).rgb;
			float tot = 1.0 + float(abs(i) + abs(j));
			sum += col / tot;
			total += tot;
		}
	}

	return (total * sum) / (36.0 * 36.0);
}

void main()
{
	vec2 pos = (vec2(1.0, 1.0) + UV) / 2.0;

	//pos += 0.15 * vec2(getPerlin(vec4(UV / 6.0, 0.0, 0.0), 1.0, 3.0, 1.0), getPerlin(vec4(UV / 6.0, 0.0, 1.0), 1.0, 3.0, 1.0));

	COLOUR = texture2D(RENDER_TEXTURE, pos).rgb;

	/*vec3 sum = vec3(0.0, 0.0, 0.0);
	float total = 0.0;

	for (float kernel_size = 3.0; kernel_size > 1.0; kernel_size *= 0.5)
	{
		for (float i = -kernel_size; i < kernel_size; i += 1.0)
		{
			for (float j = -kernel_size; j < kernel_size; j += 1.0)
			{
				vec3 col = texture2D(RENDER_TEXTURE, pos + vec2(i, j) * 0.003 * pow(kernel_size, 1.0)).rgb;

				sum += pow(col, vec3(2.0));

				total += 0.1 * (kernel_size * kernel_size - abs(i) * abs(j));
			}
		}
	}*/

	/*vec3 sum = vec3(0.0);
	vec2 total = vec2(0.0);
	for (float size = 128.0; size > 64.0; size *= 0.5)
	{
		vec3 col00 = getGaussianAt((floor(pos * size) + vec2(0.0, 0.0)) / size, size);
		vec3 col01 = getGaussianAt((floor(pos * size) + vec2(0.0, 1.0)) / size, size);
		vec3 col10 = getGaussianAt((floor(pos * size) + vec2(1.0, 0.0)) / size, size);
		vec3 col11 = getGaussianAt((floor(pos * size) + vec2(1.0, 1.0)) / size, size);

		float dx = fract(pos.x * size);
		float dy = fract(pos.y * size);

		sum += mix(mix(col00, col10, dx), mix(col01, col11, dx), dy);
		//total.x += sqrt(size);
		//total.y += 1.0;
	}

	COLOUR += pow(sum / 1.0, vec3(3.0));*/

	//COLOUR = getSizeBlob();

	//Faded corners
	COLOUR *= mix(vec3(0.0, 0.0, 0.0), vec3(1.0, 1.0, 1.0), min(1, 1.5 - length(UV)));


}
