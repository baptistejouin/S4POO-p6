#pragma once

#include <p6/p6.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include "Boids/boid.hpp"
#include "Camera/trackball.hpp"
#include "Environment/environment.hpp"
#include "Renderer/mesh.hpp"

class Renderer {
public:
    Renderer() = default;

    // TODO(baptistejouin) ctx is pass only for the aspect ratio, maybe we can find a better way to do it
    void render_boids(p6::Context& ctx, TrackballCamera& camera, const std::vector<Boid>& boids, const std::vector<Element>& point_light) const;
    void render_terrain(p6::Context& ctx, TrackballCamera& camera, const Element& terrain, const std::vector<Element>& point_light) const;
    void render_point_light(p6::Context& ctx, TrackballCamera& camera, const std::vector<Element>& point_light) const;

private:
    // fs : point_light, textures, normals

    Mesh _boids_mesh = Mesh(
        "assets/models/oiseauBake.obj",
        "assets/textures/oiseauBake.jpg",
        {"assets/shaders/3D.vs.glsl", "assets/shaders/point_light.fs.glsl"}
    );
    Mesh _terrain_mesh = Mesh(
        "assets/models/terrain.bake.obj",
        "assets/textures/terrain.bake.col.png",
        {"assets/shaders/3D.vs.glsl", "assets/shaders/point_light.fs.glsl"}
    );

    Mesh _point_light_mesh = Mesh(
        Geometry::sphere_vertices(1.0f, 10, 10),
        {"assets/shaders/3D.vs.glsl", "assets/shaders/normals.fs.glsl"}
    );
};