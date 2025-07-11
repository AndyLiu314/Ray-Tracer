#include "utility/raytracer.h"

#include "geometry/hittable.h"
#include "geometry/hittable_list.h"
#include "geometry/sphere.h"
#include "geometry/material.h"

int main() {

    // Initialize Camera
    
    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 800;
    cam.samples_per_pixel = 50;
    cam.max_recursion_depth = 10;

    cam.vfov = 45;
    cam.lookfrom = point3(-2,2,1);
    cam.lookat   = point3(0,0,-1);
    cam.vup      = vec3(0,1,0);

    // Materials 
    // auto material_center = make_shared<lambertian>(colour(0.6, 0.2, 0.2));

    auto material_ground = make_shared<lambertian>(colour(0.3, 0.6, 0.3));
    auto material_left   = make_shared<metal>(colour(0.8, 0.8, 0.8), 0.1);
    auto material_right  = make_shared<metal>(colour(0.8, 0.6, 0.2), 1.0);
    auto material_center   = make_shared<dielectric>(1.50);
    auto material_bubble = make_shared<dielectric>(1.00 / 1.50);

    // World

    hittable_list world;

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.2),   0.5, material_center));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.2),   0.4, material_bubble));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));

    // Render

    cam.render(world);
}
