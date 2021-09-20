#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"
class sphere {
  private:
    float radius;
    vec3 center;
  public:
    sphere() : radius(1) {}
    sphere(double r, vec3 c) : radius(r), center(c) {}

    bool hit(const ray &r);

};

#endif
