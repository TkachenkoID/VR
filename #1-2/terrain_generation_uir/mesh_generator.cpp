#include "mesh_generator.h"

void generation_vertex_filter(vec3& vertex, vec3& color, void* p_parameter)
{
    terrain_generation_properties* p_genproperties = (terrain_generation_properties*)p_parameter;
    SimplexNoise pnoise;
    float x = p_genproperties->seed + vertex.x;
    float z = p_genproperties->seed + vertex.z;

    float ysmall_noise = pnoise.noise(x, z) * p_genproperties->small_noiseK;

    float xpos = (x / p_genproperties->world_width) * p_genproperties->frequency;
    float zpos = (z / p_genproperties->world_width) * p_genproperties->frequency;
    float ypos = (pnoise.noise(xpos, zpos) * p_genproperties->amplitude) + ysmall_noise;
    vertex.y = ypos * p_genproperties->multiplier;

    // Calculate color based on height
    float normalizedHeight = vertex.y / 5; // Normalize height to range [0, 1]

    // Interpolate colors smoothly
    color = vec3(normalizedHeight, 0.5f - normalizedHeight, 1.0f - normalizedHeight);
}


void generate_triangles_plane_noise(std::vector<vec3>& dest_verts, std::vector<vec3>& dest_colors, std::vector<unsigned int>& dest_indices, float xpos, float ypos, float zpos, float width_x, float width_y, float step, void* p_parameter)
{
    vec3 p1, p2, p3, color1, color2, color3;
    int indice1, indice2;
    float half_width_x = width_x / 2.f;
    float half_width_y = width_y / 2.f;
    for (int x = xpos - half_width_x; x < xpos + half_width_x; x += step) {
        for (int z = zpos - half_width_y; z < zpos + half_width_y; z += step) {
            //создаем первый треугольник
            p1 = vec3((float)x, ypos, (float)z);
            generation_vertex_filter(p1, color1, p_parameter);
            dest_verts.push_back(p1);
            dest_colors.push_back(color1);
            dest_indices.push_back(dest_verts.size() - 1);

            p2 = vec3((float)x + step, ypos, (float)z);
            generation_vertex_filter(p2, color2, p_parameter);
            dest_verts.push_back(p2);
            dest_colors.push_back(color2);
            indice1 = dest_verts.size() - 1;
            dest_indices.push_back(indice1);

            p3 = vec3((float)x, ypos, (float)z + step);
            generation_vertex_filter(p3, color3, p_parameter);
            dest_verts.push_back(p3);
            dest_colors.push_back(color3);
            indice2 = dest_verts.size() - 1;
            dest_indices.push_back(indice2);

            //создаем второй треугольник
            dest_indices.push_back(indice1);
            dest_indices.push_back(indice2);

            p2 = vec3((float)x + step, ypos, (float)z + step);
            generation_vertex_filter(p2, color2, p_parameter);
            dest_verts.push_back(p2);
            dest_colors.push_back(color2);
            dest_indices.push_back(dest_verts.size() - 1);
        }
    }
}

void generate_terrain_mesh(terrain_generation_properties *p_genproperties, std::vector<vec3>& dest_colors, std::vector<vec3>& dest_verts, std::vector<unsigned int>& dest_indices)
{
	dest_verts.clear();
    dest_colors.clear();
	dest_indices.clear();
	generate_triangles_plane_noise(dest_verts, dest_colors, dest_indices, 0.f, 0.f, 0.f,
		p_genproperties->world_width, p_genproperties->world_width,
		p_genproperties->verts_step, p_genproperties);
}
