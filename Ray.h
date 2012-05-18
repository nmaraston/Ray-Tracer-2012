#ifndef _RAY_H_
#define _RAY_H_


#include "Vector.h"


/*
 * A ray is line emanating from the eye of the camera. Mathematically, we model this with a
 * parameteric equation of a line.
 */
class Ray {

	public:
	
		// Constructor.
		inline Ray(Vector3d& origin, Vector3d& direction);
		

		// Evaluate ray function with parameter t: origin + t * direction.
		inline Vector3d operator()(double t) const;


		// Setters for direction and origin.
		inline void setOrigin(Vector3d& origin);
		inline void setDirection(Vector3d& direction);


		Vector3d origin;
		Vector3d direction;

};


// Inline implementation.


/*
 * Constructor.
 */
inline
Ray::Ray(Vector3d& origin, Vector3d& direction)
	: origin(origin), direction(direction)
{}


/*
 * Evaluates ray function at value t.
 */
inline
Vector3d Ray::operator()(double t) const
{
	return origin + t * direction;
}


/*
 * Origin setter.
 */
inline
void Ray::setOrigin(Vector3d& origin)
{
	this->origin = origin;
}
	

/*
 * Direction setter.
 */
inline
void Ray::setDirection(Vector3d& direction)
{
	this->direction = direction;
}


#endif // _RAY_H_
