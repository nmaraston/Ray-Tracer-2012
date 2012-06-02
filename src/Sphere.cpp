#include <math.h>

#include "Sphere.h"
#include "Ray.h"
#include "vector_ops.h"


/*
 * Computing the intersection between a parametric line and sphere surface neatly simplifies down to
 * solving a quadtraic equation. To do this efficiently, we use the quadratic formula and first 
 * calculate the discriminant. If the discriminant is negative, no intersection occurs, if it is
 * 0, intersection occurs and one point and if it is positive then intersection occurs at two 
 * points. We solve for the smallest value t in the range [t0, t1] such that the point ray(t) 
 * intersects with the sphere.
 */
bool Sphere::hit(const Ray &ray, double t0, double t1, double* t_hit) const
{
	Vector3d o_c = ray.origin - center; 
	double a = dot_product(ray.direction, ray.direction);
	double b = dot_product(ray.direction, o_c);
	double c = dot_product(o_c, o_c) - pow(radius, 2);

	double discriminant = pow(b, 2) - a * c;

	if (discriminant < 0) {
		// No real roots. The ray does not intersect with the sphere.
		return false;
	}

	double t;

	// To compute the roots we first compute the smaller root in a manor that avoids catastrophic
	// cancellation. Then, if necessary, compute the second root using the identity x_1 * x_2 = c/a.
	if (b > 0) {
		t = (-b - sqrt(discriminant)) / a;
	} else {
		t = c / (-b + sqrt(discriminant));
	}

	// If the smaller root does not fall in range of [t0, t1], then compute the larger root and see 
	// if it falls in range.
	if (!(t0 < t && t < t1)) {
		t = c / (a * t);
		if (!(t0 < t && t < t1)) {
			return false;
		}
	}

	*t_hit = t;

	return true;
}


/*
 * Returns the normal to the given point on the surface. Assumes that the point is on the surface.
 */
Vector3d Sphere::normal(const Vector3d& point) const
{
	return (point - center) / radius;
}


/*
 * Returns an axis-aligned box that bounds the sphere.
 */
Box Sphere::bounding_box() const
{
	Vector3d min(center(0) - radius, center(1) - radius, center(2) - radius);
	Vector3d max(center(0) + radius, center(1) + radius, center(2) + radius);
	return Box(min, max);
}


	

