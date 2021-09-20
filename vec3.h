#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <math.h>

class vec3 {
  private:
    float v[3];

  public:
    vec3() : v{0,0,0} {}
    vec3(float x, float y, float z) : v{x, y, z} {}

    float x() const { return v[0]; }
    float y() const { return v[1]; }
    float z() const { return v[2]; }

    float r() const { return v[0]; }
    float g() const { return v[1]; }
    float b() const { return v[2]; }

    //Array syntax
    float operator[](int i) const { return v[i]; }
    float &operator[](int i) { return v[i]; }

    //Vector Arithmitic
    vec3 operator-() const { return vec3(-v[0], -v[1], -v[2]); }
    vec3 &operator+() { return *this; }

    vec3 &operator+=(const vec3 &u) {
      v[0] += u.v[0];
      v[1] += u.v[1];
      v[2] += u.v[2];
      return *this;
    }

    vec3 &operator-=(const vec3 &u) {
      v[0] -= u.v[0];
      v[1] -= u.v[1];
      v[2] -= u.v[2];
      return *this;
    }

    vec3 &operator*=(const vec3 &u) {
      v[0] *= u.v[0];
      v[1] *= u.v[1];
      v[2] *= u.v[2];
      return *this;
    }

    vec3 &operator/=(const vec3 &u) {
      v[0] /= u.v[0];
      v[1] /= u.v[1];
      v[2] /= u.v[2];
      return *this;
    }
    vec3& operator*=(const double f) {
      v[0] *= f;
      v[1] *= f;
      v[2] *= f;
      return *this;
    }

    vec3& operator/=(const double f) {
      v[0] /= f;
      v[1] /= f;
      v[2] /= f;
      return *this;
    }

    vec3 operator+(const vec3 &u) const {
      return vec3(v[0] + u.v[0], v[1] + u.v[1], v[2] + u.v[2]);
    }

    vec3 operator-(const vec3 &u) const {
      return vec3(v[0] - u.v[0], v[1] - u.v[1], v[2] - u.v[2]);
    }

    vec3 operator*(const vec3 &u) const {
       return vec3(v[0] * u.v[0], v[1] * u.v[1], v[2] * u.v[2]);   
    }

    vec3 operator*(double f) const {
      return vec3(v[0] * f, v[1] * f, v[2] * f);
    }

    vec3 operator/(double f) const {
      return vec3(v[0]/f, v[1]/f, v[2]/f);
    }

    friend vec3 operator*(double f, const vec3 &u) {
      return vec3(f/u.v[0], f/u.v[1], f/u.v[2]);
    }

    friend vec3 operator/(double f, const vec3 &u) {
      return vec3(f/u.v[0], f/u.v[1], f/u.v[2]);
    }

    //Vector Operations
   
    float length() const { 
      return sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    }
    float sq_length() const { 
      return v[0]*v[0] + v[1]*v[1] + v[2]*v[2]; 
    }

    vec3 unit() const {
      double recip = 1/sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
      return vec3(v[0]*recip, v[1]*recip, v[2]*recip);
    }

    float dot(const vec3 &u) const {
      return v[0]*u.v[0] + v[1]*u.v[1] + v[2]*u.v[2];
    }

    vec3 cross(const vec3 &u) const {
      return vec3(v[1]*u.v[2] - v[2] * u.v[1],
		  v[2]*u.v[0] - v[0] * u.v[2],
		  v[0]*u.v[1] - v[1] * u.v[0]);
    }

  friend std::ostream &operator<<(std::ostream &out, const vec3 &u) {
    return out << u.v[0] << ' ' << u.v[1] << ' ' << u.v[2];
  }

  friend std::istream &operator>>(std::istream &in, vec3 &u) {
    return in >> u.v[0] >> u.v[1] >> u.v[2];
  }
};

typedef vec3 color;

#endif
