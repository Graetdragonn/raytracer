#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"

class camera {
  private:
    vec3 position;
    vec3 direction;
  public:
    camera() : position() {}
    camera(vec3 pos) : position(pos), direction(0, 0, 1) {}
    vec3 pos() const { return position; }

};

#endif
