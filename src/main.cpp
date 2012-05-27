#include "Scene.h"
#include "Sphere.h"
#include "Light.h"
#include "Camera.h"
#include "Vector.h"
#include "Renderer.h"

/* 
 * Ray-tracing demo.
 */
int main(int argc, char** argv)
{	
	Vector3d sphere_center(0, 0, -14);
	Sphere sphere(sphere_center, 8);

	Vector3d light1_origin(5, 5, -1);
	Light light1(light1_origin, 1);

	Vector3d light2_origin(-5, 0, -2);
	Light light2(light2_origin, 1);
	
	// Set up the scene with a single sphere sitting in the negative region of the z-axis.
	Scene scene;
	scene.add_surface(&sphere);
	scene.add_light(&light1);
	scene.add_light(&light2);

	// Set up camera on the z-axis directed towards the negative region of the z-axis with a focal
	// distance of 5.
	Vector3d cam_origin(0, 0, 1);
	Vector3d cam_direction(0, 0, -1);
	Vector3d up(0, 1, 0);
	Camera cam(cam_origin, cam_direction, up, 5);

	// Image speifications.
	ImagePlane imgpl(14, 14, 200, 200);

	// Set up the renderer.
	Renderer renderer(&scene, &cam, &imgpl);

	// Say cheese.
	renderer.render();

	return 0;
}
	
