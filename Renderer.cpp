#include <algorithm>

#include "Renderer.h"
#include "Image.h"
#include "Ray.h"
#include "Scene.h"
#include "HitRecord.h"
#include "Spectrum.h"
#include "vector_ops.h"


/*
 * 
 */
void Renderer::render()
{
	
	unsigned rows = imgpl->vres;
	unsigned cols = imgpl->hres;

	// Output image.
	Image<byte> output(rows, cols, 3);
	
	// A single ray object is reused throughout the procedure.
	Ray ray;
	ray.origin = cam->origin;

	// Records intersection information on each iteration.
	HitRecord hit_rec;

	// Used to hold computed colour values.
	Spectrum colour;


	// Iterate through each pixel.
	for (unsigned i = 0; i < rows; ++i) {
		for (unsigned j = 0; j < cols; ++j) {

			compute_ray_direction(&ray, i, j);

			if (compute_ray_intersection(ray, &hit_rec)) {
				compute_surface_shading(hit_rec, &colour);
				//colour = hit_rec.surface->get_material()->get_kd();
			} else {
				colour = scene->get_background_colour();
			}

			set_pixel(output, i, j, colour);
		}
	}

	output.save_ppm("Render.ppm");	
}


/*
 * 
 */
void Renderer::compute_ray_direction(Ray* ray, unsigned i, unsigned j)
{
	double v;
	double u;
 
	v = imgpl->bottom + imgpl->height * (double(i) + 0.5) / imgpl->vres;
	u = imgpl->left + imgpl->width * (double(j) + 0.5) / imgpl->hres;

	ray->direction = ( -cam->focal_distance * cam->w ) + ( u * cam->u ) + ( v * cam->v ); 
}
	

/*
 * The main intersection routine thats called on each iteration of the ray tracing procedure. 
 * This function computes the closest intersection point to the camera between the given ray and
 * all surfaces in the scene. 
 */
bool Renderer::compute_ray_intersection(const Ray& ray, HitRecord* hit_rec)
{
	double t0 = 0;
	double t1 = 1000;
	double t_hit;
	bool hit_flag = false;

	// Find the closest surface that intersects this ray.
	Surface* surface;
	for (unsigned i = 0; i < scene->get_surfaces().size(); ++i) {
		surface = scene->get_surfaces()[i];
		if (surface->hit(ray, t0, t1, &t_hit)) {
			t1 = t_hit;
			hit_rec->surface = surface;
			hit_flag = true;
		}
	}

	// If a hit was detected, compute the point of intersection and normal.
	if (hit_flag) {
		hit_rec->t = t1;
		hit_rec->point = ray.origin + t1 * ray.direction;
		hit_rec->normal = surface->normal(hit_rec->point);
	}
	
	return hit_flag;
}


/*
 * Currently, surface shading is computed using lambertian shading model.
 */
void Renderer::compute_surface_shading(const HitRecord& hit_rec, Spectrum* colour)
{
	Light* light;
	Vector3d l;
	double angle;

	// Set all components to 0.
	*colour = Spectrum::BLACK;

	// The material of the intersected surface.
	const Material* material = hit_rec.surface->get_material();

	// Accumulate the value of the lambertian formula evaluated with each light source.
	for (unsigned i = 0; i < scene->get_lights().size(); ++i) {
		light = scene->get_lights()[i];
		l = (light->origin - hit_rec.point).normalize();
		angle = std::max(0.0, dot_product(hit_rec.normal, l));
		*colour += material->get_kd() * light->intensity * angle;
	}

	colour->clamp();
}


/*
 * Helper function for ray tracing algorithm. Sets the colour of image output at pixel 
 * position (i,j).
 */
inline
void Renderer::set_pixel(Image<byte>& output, unsigned i, unsigned j, const Spectrum& colour)
{
	output(i,j,0) = colour.r * 255;
	output(i,j,1) = colour.g * 255;
	output(i,j,2) = colour.b * 255;
}

