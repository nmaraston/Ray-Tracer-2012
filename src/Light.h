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
	
		// Position of light in the coordinate system.
		Vector3d origin;
	
		// Light intensity.
		double intensity;

};


// Inline implementations:


/*
 * Constructs a light surce positioned at the given origin with the given intensity.
 */
inline
Light::Light(const Vector3d& _origin, double _intensity)
	: origin(_origin), intensity(_intensity)
{}


#endif // _LIGHT_H_
