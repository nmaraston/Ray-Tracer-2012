#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_

#include "Vector.h"

class Vector3d : public Vector<double>
{
	public: 
		
		// Constructor.
		// A new vector of the form (a,b,c,).
		Vector3d(double a = 0, double b = 0, double c = 0);
};
	


#endif // _VECTOR3D_H_
