#include "Vector3d.h"

// Implementation of Vector3d class.

/*
 * Constructor.
 */
Vector3d::Vector3d(double a, double b, double c)
	: Vector<double>(3)
{
	(*this)(0) = a;
	(*this)(1) = b;
	(*this)(2) = c;
}
