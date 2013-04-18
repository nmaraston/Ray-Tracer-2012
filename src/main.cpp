#include "Scene.h"
#include "Sphere.h"
#include "Light.h"
#include "Camera.h"
#include "Vector.h"
#include "Renderer.h"

/* 
 * Ray-tracer demo.
 */
int main(int argc, char** argv)
{	
	// Create materials.
	Material turquoise(Spectrum(0.17, 0.68, 0.59));
	Material yellow(Spectrum(0.68, 0.87, 0.3));
	Material pink(Spectrum(0.89, 0.47, 0.47));

	// Create scene geometry (only spheres).
	Vector3d sphere1_center(-20, 20, -60);
	Sphere sphere1(sphere1_center, 18, &turquoise);

    Vector3d sphere2_center(20, 20, -60);
    Sphere sphere2(sphere2_center, 18, &yellow);

    Vector3d sphere3_center(-20, -20, -60);
    Sphere sphere3(sphere3_center, 18, &pink);

    Vector3d sphere4_center(20, -20, -60);
    Sphere sphere4(sphere4_center, 18);

	// Create lights (only point lights).
	Vector3d light1_origin(-40, 20, 0);
	Vector3d light2_origin(50, 20, 0);
	Light light1(light1_origin, 0.4);
	Light light2(light2_origin, 0.8);

	// Set up the scene with a single sphere sitting in the negative region of 
	// the z-axis.
	Scene scene;
    scene.add_surface(&sphere1);
	scene.add_surface(&sphere2);
	scene.add_surface(&sphere3);
	scene.add_surface(&sphere4);
	scene.add_light(&light1);
	scene.add_light(&light2);

	// Set up camera on the z-axis directed towards the negative region of the 
	// z-axis with a focal distance of 5.
	Vector3d cam_origin(0, 0, 0);
	Vector3d cam_direction(0, 0, -1);
	Vector3d up(0, 1, 0);
	Camera cam(cam_origin, cam_direction, up, 100);

	// Image speifications.
	ImagePlane imgpl(200, 150, 600, 450);

	// Set up the renderer.
	Renderer renderer(&scene, &cam, &imgpl);

	// Say cheese.
	renderer.render();

	return 0;
}
	
