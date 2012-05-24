#ifndef _CAMERA_H_
#define _CAMERA_H_


#include "Vector.h"


/*
 *
 */
class Camera {
	
	public:
		
		// Constructor.
		Camera(const Vector3d& origin, const Vector3d& direction, const Vector3d& up, 
			   double focal_distance);
		
		// Viewpoint position.
		Vector3d origin;

		// A right handed orthonormal basis with respect to the cameras orientation. 
		// The view-direction is equivalent to -w.
		Vector3d w;
		Vector3d u;
		Vector3d v;

		double focal_distance;

};


#endif // _CAMERA_H_
