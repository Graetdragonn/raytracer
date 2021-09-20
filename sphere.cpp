#include "sphere.h"

  bool sphere::hit(const ray &r) {
    vec3 oc = (r.origin() - center);
    
    double a = r.dir().sq_length();
    double b = 2*r.dir().dot(oc);
    double c = oc.sq_length() - radius * radius;
    
    double sqroot = b*b - 4*a*c;
    if (sqroot < 0) return false;
    
    return true;
    //double sqrd = sqrt(sqroot);
    //(-b - sqrd)/2a ;
    
  }

