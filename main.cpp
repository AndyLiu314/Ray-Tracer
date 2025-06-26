#include "utility/raytracer.h"

#include "geometry/hittable.h"
#include "geometry/hittable_list.h"
#include "geometry/sphere.h"

int main() {

    // Initialize Camera
    
    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;

    // World

    hittable_list world;

    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    // Render

    cam.render(world);
}
