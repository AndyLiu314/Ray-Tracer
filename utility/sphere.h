#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
    public:
        sphere(const point3& center, double radius) : center(center), radius(std::fmax(0, radius)) {}

        bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& record) const override {
            vec3 oc = center - r.origin();
            auto a = r.direction().length_squared();
            auto h = dot(r.direction(), oc);
            auto c = oc.length_squared() - radius*radius;
            auto discriminant = h*h - a*c;

            if (discriminant < 0) {
                return false;
            }

            auto sqrt_discr = std::sqrt(discriminant);

            // chooses the nearest root (i.e the nearest intersection point) first
            auto root = (h - sqrt_discr) / a;
            if (root <= ray_tmin || root >= ray_tmax) {
                root = (h + sqrt_discr) / a;
                if (root <= ray_tmin || root >= ray_tmax) {
                    return false;
                }
            }

            record.t = root;
            record.p = r.at(record.t);
            vec3 outward_normal = (record.p - center) / radius; // Divides by radius to normalize the vector
            record.set_face_normal(r, outward_normal);

            return true;
        }

    private:
        point3 center;
        double radius;
};

#endif