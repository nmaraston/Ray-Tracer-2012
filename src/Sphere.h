#ifndef _SPHERE_H_
#define _SPHERE_H_


#include "Vector.h"
#include "Surface.h"
#include "Ray.h"
#include "Box.h"


/*
 *
 */
class Sphere : public Surface {

	public:
	
		// Constructors.
		inline Sphere(const Vector3d& center, double radius);
		inline Sphere(const Vector3d& center, double radius, const Material* material);


		// Hit detection.
		virtual bool hit(const Ray& ray, double t0, double t1, double* hit_t) const;

		// Returns the normal to the given point on the surface.
		virtual Vector3d normal(const Vector3d& point) const;

		// Returns an axis-aligned bounding box for this surface.
		virtual Box bounding_box() const;

	
		Vector3d center;
		double radius;	

};


// Inline implementations:


/*
 * Creates a Sphere with the given center and radius and default grey material.
 */
inline
Sphere::Sphere(const Vector3d& _center, double _radius)
	: Surface(), center(_center), radius(_radius)
{}


/*
 * Creates a Sphere with the given center, radius and material.
 */
inline
Sphere::Sphere(const Vector3d& _center, double _radius, const Material* material)
	: Surface(material), center(_center), radius(_radius)
{}


#endif // _SPHERE_H_
