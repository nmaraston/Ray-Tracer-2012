#ifndef _SURFACE_H_
#define _SURFACE_H_


#include "Material.h"
#include "Ray.h"
#include "Hit_Record.h"
#include "Box.h"


/* 
 * Abstract class surface. 
 * A surface must be able to determine if and where a given ray intersects it and must be able to
 * supply an axis-aligned bounding box.
 */
class Surface {

	public:

		// Constructors:
		inline Surface();
		inline Surface(Material& material);
		
		/*
 		 * Returns true if and only if the ray intersects this surface. If intersection does occur,
		 * the intersection information (location and normal) are written to hit_record.
 		 */
		virtual bool hit(Ray& ray, double t0, double t1, Hit_Record* hit_record) = 0;

		/* 
		 * Returns and axis-aligned bounding box.
 		 */
		virtual Box bounding_box() = 0;

	
		// Material access:
		inline Material& material();
		inline void set_material(Material& material);

	private:

		Material material_;

};


// Inline implementations:
	

/*
 * Default constructor. Creates a surface with default grey material.
 */
inline
Surface::Surface() 
{}


/*
 * Constructs a surface with the given material.
 */ 
inline
Surface::Surface(Material& material)
	: material_(material)
{}


/*
 * Material access.
 */
inline 
Material& Surface::material()
{
	return material_;
}

inline
void Surface::set_material(Material& material)
{
	material_ = material;
}


#endif // _SURFACE_H_
