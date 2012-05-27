#ifndef _LIGHT_H_
#define _LIGHT_H_


#include "Vector.h"


/*
 * A light source is modeled with a position (origin) and intensity.
 */
struct Light {
	
	public: 
		
		// Constructor.
		inline Light(const Vector3d& origin, double intensity);

		// Intenity of this light source.
		double intensity;

		// Position of light in the coordinate system.
		Vector3d origin;

};


// Inline implementations:


/*
 * Constructs a light surce positioned at the given origin with the given intensity.
 */
inline
Light::Light(const Vector3d& _origin, double _intensity)
	:	intensity(_intensity), origin(_origin)
{}


#endif // _LIGHT_H_
