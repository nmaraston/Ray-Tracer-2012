#ifndef _MATERIAL_H_
#define _MATERIAL_H_


#include "Spectrum.h"


// TODO: Document Material class.
/*
 * 
 */
class Material {

	public:

		// Consturctor. Default material is grey.
		inline Material(const Spectrum& kd = Spectrum::GREY, const Spectrum& ks = Spectrum::GREY);
		
		
		// ACCESSORS:
		inline const Spectrum& get_kd() const;
		inline void set_kd(const Spectrum& kd);

		inline const Spectrum& get_ks() const;
		inline void set_ks(const Spectrum& ks);

	private:
		
		Spectrum kd_;
		Spectrum ks_;


	public:
		
		// Some useful materials:
		static const Material MATTE_GREY;
};


// Inline implementations:


/*
 *
 */
inline 
Material::Material(const Spectrum& kd, const Spectrum& ks)
	: kd_(kd), ks_(ks)
{}


/*
 *
 */
inline
const Spectrum& Material::get_kd() const
{
	return kd_;
}


/*
 *
 */
inline
void Material::set_kd(const Spectrum& kd)
{
	kd_ = kd;
}


/*
 *
 */
inline
const Spectrum& Material::get_ks() const
{
	return ks_;
}


/*
 *
 */
inline
void Material::set_ks(const Spectrum& ks)
{
	ks_ = ks;
}


#endif // _MATERIAL_H_
