#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Vector_3D.h"

class Camera {
	
	public:
		
		// Constructor.
		Camera(Vector_3D &view_point, Vector_3D &view_direction, Vector_3D &up);
		
		// Viewpoint position.
		Vector_3D e;

		// A right handed orthonormal basis with respect to the cameras orientation. 
		// The view-direction is equivalent to -w.
		Vector_3D w;
		Vector_3D u;
		Vector_3D v;
};

#endif // _CAMERA_H_
