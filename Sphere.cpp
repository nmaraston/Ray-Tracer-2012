#include <math.h>
#include <iostream>

#include "Sphere.h"
#include "Ray.h"
#include "Hit_Record.h"
#include "vector_ops.h"


/*
 * Computing the intersection between a parametric line and sphere surface neatly simplifies down to
 * solving a quadtraic equation. To do this efficiently, we use the quadratic formula and first 
 * calculate the discriminant. If the discriminant is negative, no intersection occurs, if it is
 * 0, intersection occurs and one point and if it is positive then intersection occurs at two 
 * points. We solve for the smallest value t in the range [t0, t1] such that the point ray(t) 
 * intersects with the sphere.
 */
bool Sphere::hit(Ray &ray, double t0, double t1, Hit_Record* hit_record)
{
	Vector3d o_c = ray.origin - center; 
	double a = dot_product(ray.direction, ray.direction);
	double b = dot_product(ray.direction, o_c);
	double c = dot_product(o_c, o_c) - pow(radius, 2);

	double dis = pow(b, 2) - a * c;

	// No real roots. The ray does not intersect with the sphere.
	if (dis < 0) {
		return false;
	}

	double hit_t;

	// To compute the roots we first compute the smaller root in a manor that avoids catastrophic
	// cancellation. Then, if necessary, compute the second root using the identity x_1 * x_2 = c/a.
	if (b > 0) {
		hit_t = (-b - sqrt(dis)) / a;
	} else {
		hit_t = c / (-b + sqrt(dis));
	}

	// If the smaller intersection point does not fall in range of [t0, t1], then compute the 
	// larger intersection point and see if it falls in range.
	if (!(t0 < hit_t && hit_t < t1)) {
		hit_t = c / (a * hit_t);
		if (!(t0 < hit_t && hit_t < t1)) {
			return false;
		}
	}

	hit_record->t = hit_t;
	hit_record->point = ray(hit_t);

	// Computing the unit normal to the intersection point.
	hit_record->normal = (hit_record->point - center) / radius;

	return true;
}


/*
 * Returns an axis-aligned box that bounds the sphere.
 */
Box Sphere::bounding_box()
{
	Vector3d min(center(0) - radius, center(1) - radius, center(2) - radius);
	Vector3d max(center(0) + radius, center(1) + radius, center(2) + radius);
	return Box(min, max);
}


	

