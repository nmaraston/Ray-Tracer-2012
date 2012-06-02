#ifndef _SURFACE_H_
#define _SURFACE_H_


#include "Material.h"
#include "Ray.h"
#include "Box.h"
#include "Spectrum.h"


/* 
 * Abstract surface class.
 * A surface must be able to determine if and where a given ray intersects it and must be able to
 * supply an axis-aligned bounding box.
 */
class Surface {

	public:

		// Constructors:
		inline Surface();
		inline Surface(const Material* material);
		

 		// Returns true if and only if the ray intersects this surface. If intersection does occur,
		// the intersection information (location and normal) are written to hit_record.
		virtual bool hit(const Ray& ray, double t0, double t1, double* hit_t) const = 0;

		// Returns the normal to the given point on the sphere. Assumes the point is on the surface.
		virtual Vector3d normal(const Vector3d& point) const = 0;

		// Returns and axis-aligned bounding box.
		virtual Box bounding_box() const = 0;

	
		// Material access:
		inline const Material* get_material() const;
		inline void set_material(const Material* material);

	private:

		const Material* material_;

};


// Inline implementations:
	

/*
 * Default constructor. Creates a surface with default grey material.
 */
inline
Surface::Surface()
	: material_(&Material::MATTE_GREY)
{}



/*
 * Constructs a surface with the given material.
 */ 
inline
Surface::Surface(const Material* material)
	: material_(material)
{}


/*
 * Material access.
 */
inline 
const Material* Surface::get_material() const
{
	return material_;
}

inline
void Surface::set_material(const Material* material)
{
	material_ = material;
}


#endif // _SURFACE_H_
