#ifndef _HIT_RECORD_H_
#define _HIT_RECORD_H_


#include "Vector.h"
#include "Surface.h"


/*
 * A hit-record is a collection of information that is filled out when a Surface class's hit method
 * detects intersection.
 */
struct HitRecord {

	// A pointer to the closest surface that was hit by the ray.
	const Surface* surface;
	
	// Parameter value where ray(t) intersects the surface.
	double t;

	// The point of intersection.
	Vector3d point;
	
	// The unit normal of the surface at the intersecton point.
	Vector3d normal;

};


#endif // _HIT_RECORD_H_
