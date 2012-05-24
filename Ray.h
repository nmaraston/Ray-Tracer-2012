#ifndef _RAY_H_
#define _RAY_H_


#include "Vector.h"


/*
 * A ray is line emanating from the eye of the camera. Mathematically, we model this with a
 * parameteric equation of a line.
 */
struct Ray {

	public:

		// Constructors. 
		inline Ray();
		inline Ray(Vector3d& origin, Vector3d& direction);
		
		Vector3d origin;
		Vector3d direction;

};


// Inline implementation.


/* 
 * Constructs a ray with a zero vector for the origin and direction.
 */
inline
Ray::Ray()
	: origin(0, 0, 0), direction(0, 0, 0)
{}


/*
 * Constructs a ray of the form: ray(t) = origin + t * direction
 */
inline
Ray::Ray(Vector3d& origin, Vector3d& direction)
	: origin(origin), direction(direction)
{}


#endif // _RAY_H_
