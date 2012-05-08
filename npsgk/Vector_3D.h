#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_

#include "Vector.h"

class Vector_3D : public Vector<double>
{
	public: 
		
		// Constructor.
		// A new vector of the form (a,b,c,).
		Vector_3D(double a = 0, double b = 0, double c = 0);

		using Vector<double>::operator=;
};
	


#endif // _VECTOR3D_H_
