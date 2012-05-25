#ifndef _CAMERA_H_
#define _CAMERA_H_


#include "Vector.h"


/*
 * A camera model consists of an orthonormal basis at the origin of the camera. This
 * basis is constructed with a given origin point (position of the camera), direction vector 
 * (direction the camera is facing) and up vector to provide the camera orientation. 
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
