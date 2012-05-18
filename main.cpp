#include <iostream>
#include "Sphere.h"
#include "Ray.h"

int main(int argc, char** argv)
{

	Vector3d e(0, 0, 0);
	Vector3d d(0, 1, -1);
	Ray ray(e, d);

	Vector3d c(0, 0, 0);
	Sphere sphere(c, 5);

	Hit_Record h;

	if (sphere.hit(ray, 0, 100, &h)) {
		std::cout << "Hit." << std::endl;
		std::cout << h.t << std::endl;
		std::cout << h.point(0) << ", " << h.point(1) << ", " << h.point(2) << std::endl;
	} else {
		std::cout << "No hit." << std::endl;
	}

	return 0;
}
	
