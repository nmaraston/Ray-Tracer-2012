#include "Camera.h"
#include "Vector.h"
#include "vector_ops.h"


/*
 * Constructor.
 */
Camera::Camera(const Vector3d& _origin, const Vector3d& direction, const Vector3d& up, 
			   double _focal_distance)
	: origin(_origin), focal_distance(_focal_distance)
{
	// Construct a right handed orthonormal basis.
	w = (-direction).normalize();
	u = cross_product(up, w).normalize();
	v = cross_product(w, u);
}
