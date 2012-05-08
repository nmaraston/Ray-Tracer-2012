#include "Camera.h"
#include "Vector_3D.h"
#include "vector_ops.h"


// Camera class implementation.

/*
 * Constructor.
 */
Camera::Camera(Vector_3D &view_point, Vector_3D &view_direction, Vector_3D &up)
{
	e = view_point;

	// Construct a right handed orthonormal basis.
	w = (-view_direction).normalize();
	u = cross_product(up, w).normalize();
	v = cross_product(w, u);
}
