#include "Sphere.h"
#include "Ray.h"
#include "Hit_Record.h"


// Sphere class implementation:


/*
 *
 */
bool Sphere::hit(Ray &ray, double t0, double t1, Hit_Record* hit_record)
{
	// TODO: Implement hit detection for Spheres.
	return false;
}


/*
 * Returns an axis-aligned box that bounds the sphere.
 */
Box Sphere::bounding_box()
{
	Vector3d min(center_(0) - radius_, center_(1) - radius_, center_(2) - radius_);
	Vector3d max(center_(0) + radius_, center_(1) + radius_, center_(2) + radius_);
	return Box(min, max);
}


	

