#include "Vector_3D.h"

// Implementation of Vector3d class.

/*
 * Constructor.
 */
Vector_3D::Vector_3D(double a, double b, double c)
	: Vector<double>(3)
{
	(*this)(0) = a;
	(*this)(1) = b;
	(*this)(2) = c;
}
