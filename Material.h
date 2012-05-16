#ifndef _MATERIAL_H_
#define _MATERIAL_H_


#include "RGB.h"


class Material {

	public:

		// Consturctor. Default material is grey.
		inline Material(const RGB& ambient = RGB::GREY, const RGB& surface = RGB::GREY);
	
		// Colour access:
		inline RGB& ambient();
		inline RGB& surface();

	private:
	
		RGB ambient_;
		RGB surface_;

};


// Inline implementations:


inline 
Material::Material(const RGB& ambient, const RGB& surface)
	: ambient_(ambient), surface_(surface)
{}


inline
RGB& Material::ambient()
{
	return ambient_;
}


inline
RGB& Material::surface()
{
	return surface_;
}


#endif // _MATERIAL_H_
