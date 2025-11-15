#include "rt.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

int main() {
    hittable_list world;
    
    auto material_ground = make_shared<lambertian>(color(0.5,0.5,0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, material_ground));
    
    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto rand_mat = random_double();
            point3 center(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());
            
            if ((center - point3(4,0.2,0)).length() > 0.9) {
                shared_ptr<material> sphere_material;
                
                if (rand_mat < 0.8) {
                    // diffuse mat
                    auto albedo = color::random() * color::random();
                    sphere_material = make_shared<lambertian>(albedo);
                    world.add(make_shared<sphere>(center,0.2,sphere_material));
                } else if (rand_mat < 0.95) {
                    // metal mat
                    auto albedo = color::random(0.5,1);
                    auto fuzzy = random_double(0,0.5);
                    sphere_material = make_shared<metal>(albedo,fuzzy);
                    world.add(make_shared<sphere>(center,0.2,sphere_material));
                } else {
                    // glass mat
                    sphere_material = make_shared<dielectric>(1.5);
                    world.add(make_shared<sphere>(center,0.2,sphere_material));
                }
            }
        }
    }
    
    
    
    camera cam;
    
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 1200;
    cam.samples_per_pixel = 500;
    cam.max_depth = 50;
    cam.vfov = 20;
    cam.lookfrom = point3(13,2,3);
    cam.lookat = point3(0,0,0);
    cam.up = vec3(0,1,0);
    cam.defocus_angle = 0.6;
    cam.focus_dist = 10.0;
    
    cam.render(world);
}
