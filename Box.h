#ifndef _BOX_H_
#define _BOX_H_


#include "Vector.h"


/*
 * A box in the coordinate system is represented with a two coordinates: min and max. Where min
 * would be the "back" bottom left and max in the "front" top right. Here, "back" and "front" 
 * really mean positive and negative directions along the z-axis. 
 * 
 * More mathematically: min.x < max.x, min.y < max.y, min.z < max.z
 *
 */
class Box {

	public:
		
		// Constructor.
		inline Box(Vector3d& min, Vector3d& max);

		Vector3d min;
		Vector3d max;

};


// Inline implementations:


/*
 * Constructor.
 */
inline
Box::Box(Vector3d& _min, Vector3d& _max)
	: min(_min), max(_max)
{}


#endif // _BOX_H_
