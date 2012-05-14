#include "Vector.h"
#include "Camera.h"
#include <iostream>

int main(int argc, char** argv)
{
	Vector3d position(0, 0, 1);
	Vector3d direction(0, 0, -1);
	Vector3d up(0, 1, 0);	

	Camera cam(position, direction, up);

	std::cout << "w: " << cam.w(0) << " " << cam.w(1) << " " << cam.w(2) << "\n";
	std::cout << "u: " << cam.u(0) << " " << cam.u(1) << " " << cam.u(2) << "\n";
	std::cout << "v: " << cam.v(0) << " " << cam.v(1) << " " << cam.v(2) << "\n";

	return 0;
}
	
