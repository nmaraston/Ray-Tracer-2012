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
	Vector3d sphere_center(0, 0, -10);
	Sphere sphere(sphere_center, 5);

	Vector3d light_origin(-2, 3, -1);
	Light light(light_origin, 0.5);
	
	// Set up the scene with a single sphere sitting in the negative region of the z-axis.
	Scene scene;
	scene.add_surface(&sphere);
	scene.add_light(&light);

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
	
