#include "vec3.h"
#include "sphere.h"
#include "camera.h"
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
  int i,j;
  FILE *f;
  uint8_t r,g,b;

  //Resolution
  double ratio = (double) 16/9;
  int width = 1920;
  int height = width/ratio;

  //Image Plane
  double z = 1;
  double plane_width = 4;
  double plane_height = plane_width/ratio;
  vec3 top_left(-plane_width/2, plane_height/2, 1);

  //pixel size
  double pixel_width = plane_width / width;
  double pixel_height = plane_height / height;
  camera cam = camera();
  //sphere radius = 1 & centered at point (0,0,2)
  sphere s(1, vec3(0,0,2));

  f = fopen("testing.ppm", "w");

  fprintf(f, "P6\n%d\n%d\n255\n", width, height);

  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      ray p(cam.pos(), vec3(top_left.x() + j*pixel_width,
			      top_left.y() - i*pixel_height,
			      z));
      if (s.hit(p)) {
	r = 255;
	g = 255;
	b = 255;
      } else {
	r = 0;
	g = 0;
	b = 0;
      }
      fwrite(&r, 1, sizeof(r), f);
      fwrite(&b, 1, sizeof(b), f);
      fwrite(&g, 1, sizeof(g), f);
    }
  }

  fclose(f);

  return 0;
}
