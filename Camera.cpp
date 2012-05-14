#include "Camera.h"
#include "Vector.h"
#include "vector_ops.h"


// Camera class implementation.

/*
 * Constructor.
 */
Camera::Camera(Vector3d &view_point, Vector3d &view_direction, Vector3d &up)
{
	e = view_point;

	// Construct a right handed orthonormal basis.
	w = (-view_direction).normalize();
	u = cross_product(up, w).normalize();
	v = cross_product(w, u);
}
