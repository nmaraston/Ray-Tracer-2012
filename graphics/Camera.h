#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "math/Vector3d.h"

class Camera {
	
	public:
		
		// Constructor.
		Camera(Vector3d &view_point, Vector3d &view_direction, Vector3d &up);
		
		// Viewpoint position.
		Vector3d e;

		// A right handed orthonormal basis with respect to the cameras orientation. 
		// The view-direction is equivalent to -w.
		Vector3d w;
		Vector3d u;
		Vector3d v;
};

#endif // _CAMERA_H_
