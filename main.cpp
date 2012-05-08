#include "npsgk/Vector_3D.h"
#include "npsgk/vector_ops.h"
#include "npsgk/Camera.h"
#include <iostream>

int main(int argc, char** argv)
{
	Vector_3D position(0, 0, 1);
	Vector_3D direction(0, 0, -1);
	Vector_3D up(0, 1, 0);	

	Camera cam(position, direction, up);

	std::cout << "w: " << cam.w(0) << " " << cam.w(1) << " " << cam.w(2) << "\n";
	std::cout << "u: " << cam.u(0) << " " << cam.u(1) << " " << cam.u(2) << "\n";
	std::cout << "v: " << cam.v(0) << " " << cam.v(1) << " " << cam.v(2) << "\n";


	return 0;
}
	
