#ifndef MATERIAL_H
#define MATERIAL_H

#include "hittable.h"

class material {
  public:
    virtual ~material() = default;

    virtual bool scatter(
        const ray& r_in, const hit_record& rec, colour& attenuation, ray& scattered
    ) const {
        return false;
    }
};

class lambertian : public material {
  public:
    lambertian(const colour& albedo) : albedo(albedo) {}

    bool scatter(const ray& r_in, const hit_record& rec, colour& attenuation, ray& scattered) const override {
        // if the normal and random unit vector are opposite one another, scatter_direction could be zero (not good)
        auto scatter_direction = rec.normal + random_unit_vector();
        
        // This intercepts zero scatter_direction
        if (scatter_direction.near_zero()) {
            scatter_direction = rec.normal;
        }

        scattered = ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
    }

  private:
    colour albedo;
};

class metal : public material {
  public:
    metal(const colour& albedo) : albedo(albedo) {}

    bool scatter(const ray& r_in, const hit_record& rec, colour& attenuation, ray& scattered)
    const override {
        vec3 reflected = reflect(r_in.direction(), rec.normal);
        scattered = ray(rec.p, reflected);
        attenuation = albedo;
        return true;
    }

  private:
    colour albedo;
};

#endif