#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
  private:
    vec3 og;
    vec3 d;
  public:
    ray() {}
    ray(vec3 p, vec3 dir) : og(p), d(dir) {}

    vec3 origin() const { return og; }
    vec3 dir() const { return d; }

    vec3 eval(float t) const { return og + t*d; }
};

#endif
