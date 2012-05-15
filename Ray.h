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


		// Origin access.
		inline Vector3d& origin();
		inline void setOrigin(Vector3d& origin);
	
		// Direction access.
		inline Vector3d& direction();
		inline void setDirection(Vector3d& direction);

	private:

		Vector3d origin_;
		Vector3d direction_;

};


// Inline implementation.


/*
 * Constructor.
 */
inline
Ray::Ray(Vector3d& origin, Vector3d& direction)
	: origin_(origin), direction_(direction)
{}


/*
 * Evaluates ray function at value t.
 */
inline
Vector3d Ray::operator()(double t) const
{
	return origin_ + t * direction_;
}


/*
 * Origin access.
 */
inline
Vector3d& Ray::origin()
{
	return origin_;
}

inline
void Ray::setOrigin(Vector3d& origin)
{
	origin_ = origin;
}
	

/*
 * Direction access.
 */
inline
Vector3d& Ray::direction()
{
	return direction_;
}

inline
void Ray::setDirection(Vector3d& direction)
{
	direction_ = direction;
}


#endif // _RAY_H_
