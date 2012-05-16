#ifndef _SPHERE_H_
#define _SPHERE_H_


#include "Vector.h"
#include "Surface.h"
#include "Ray.h"
#include "Hit_Record.h"
#include "Box.h"


/*
 *
 */
class Sphere : public Surface {

	public:
	
		// Constructors.
		inline Sphere(Vector3d& center, double radius);
		inline Sphere(Vector3d& center, double radius, Material& material);


		// Hit detection.
		virtual bool hit(Ray& ray, double t0, double t1, Hit_Record* hit_record);

	
		// Returns an axis-aligned bounding box for this surface.
		virtual Box bounding_box();

	
		// Access to radius and center.
		Vector3d& center();
		double radius();

	private:
	
		Vector3d center_;
		double radius_;	

};


// Inline implementations:


/*
 * Creates a Sphere with the given center and radius and default grey material.
 */
inline
Sphere::Sphere(Vector3d& center, double radius)
	: Surface(), center_(center), radius_(radius)
{}


/*
 * Creates a Sphere with the given center, radius and material.
 */
inline
Sphere::Sphere(Vector3d& center, double radius, Material& material)
	: Surface(material), center_(center), radius_(radius)
{}


#endif // _SPHERE_H_
