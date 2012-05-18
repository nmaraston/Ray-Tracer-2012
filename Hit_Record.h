#ifndef _HIT_RECORD_H_
#define _HIT_RECORD_H_


#include "Vector.h"


/*
 * A hit-record is a collection of information that is filled out when a Surface class's hit method
 * detects intersection.
 */
struct Hit_Record {

	// Parameter value where ray(t) intersects the surface.
	double t;

	// Point of intersection.
	Vector3d point;

	// The unit normal of the surface at the intersecton point.
	Vector3d normal;

};


#endif // _HIT_RECORD_H_
