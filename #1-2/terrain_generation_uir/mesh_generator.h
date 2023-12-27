#pragma once
#include "glmath.h"
#include "SimplexNoise.h"
#include <vector>

void generate_triangles_plane_noise(
	std::vector<vec3>& dest_verts,
	std::vector<vec3>& dest_colors,
	std::vector<unsigned int>& dest_indices,
	float xpos, float ypos, float zpos,
	float width_x, float width_y, float step,
	void* p_parameter);


class terrain_generation_properties {
public:
	terrain_generation_properties(float wwidth, float vstep, float freq, float ampl, float smallnoiseK, float mult) :
		world_width(wwidth), verts_step(vstep), frequency(freq), small_noiseK(smallnoiseK), amplitude(ampl), multiplier(mult) {}
	~terrain_generation_properties() {}

	float seed;
	float world_width;
	float verts_step;
	float frequency;
	float amplitude;
	float small_noiseK;
	float multiplier;
};

void generate_terrain_mesh(terrain_generation_properties *p_genproperties, std::vector<vec3>& dest_colors, std::vector<vec3>& dest_verts, std::vector<unsigned int>& dest_indices);