#ifndef _SPECTRUM_H_
#define _SPECTRUM_H_


#include <assert.h>


class Spectrum {

	public:
		
		// Constructor.
		inline Spectrum(float red = 0.f, float green = 0.f, float blue = 0.f);

		// Copy constructor.
		inline Spectrum(const Spectrum& other);

		// Assignment operator.
		inline Spectrum& operator=(const Spectrum& rhs);

		
		// MATHEMATICAL OPERATIONS:

		// Equality.
		inline bool operator==(const Spectrum& other) const;

		// Scalar multiplication. Returns new Spectrum.
		inline friend Spectrum operator*(float s, const Spectrum& col);
		inline friend Spectrum operator*(const Spectrum& col, float s);

		// Scalar division. Returns new Spectrum.
		inline Spectrum operator/(float s) const;

		// Spectrum addition and subtraction. Returns new Spectrum.
		inline Spectrum operator+(const Spectrum& other) const;
		inline Spectrum operator-(const Spectrum& other) const;

		// Accumulated scalar multiplication and division. Returns *this.
		inline Spectrum& operator*=(float s);
		inline Spectrum& operator/=(float s);

		// Accumulated spectrum addition and subtraction. Returns *this.
		inline Spectrum& operator+=(const Spectrum& other);
		inline Spectrum& operator-=(const Spectrum& other);


		// Clamp the r,g and b components between 0.f and 1.f.
		inline void clamp(void);

		// Colour components.
		float r;
		float g;
		float b;

		
		// Some helper colours.
		static const Spectrum GREY;
		static const Spectrum BLACK;

};


// Inline implementations:


/*
 * Constructor.
 */
inline
Spectrum::Spectrum(const float _red, const float _green , const float _blue)
	: r(_red), g(_green), b(_blue)
{
}


/*
 * Copy constructor.
 */
inline
Spectrum::Spectrum(const Spectrum& other)
{
	r = other.r;
	g = other.g;
	b = other.b;
}


/*
 * Assignment operator.
 */
inline
Spectrum& Spectrum::operator=(const Spectrum& rhs)
{
	r = rhs.r;
	g = rhs.g;
	b = rhs.b;
	return *this;
}


// Mathematical operators:


/*
 * Equality.
 */
inline
bool Spectrum::operator==(const Spectrum& other) const
{
	return (r == other.r) && (g == other.g) && (b == other.b);
}


/*
 * Scalar multiplication. Implemented as friend functions.
 */
inline
Spectrum operator*(const float s, const Spectrum& col)
{
	return Spectrum(s * col.r, s * col.g, s * col.b);
}

inline 
Spectrum operator*(const Spectrum& col, const float s)
{
	// For commutivity.
	return s * col;
}


/*
 * Scalar division.
 */
inline
Spectrum Spectrum::operator/(const float s) const
{
	float inv = 1.f / s;
	return Spectrum(r * inv, g * inv, b * inv);
}


/*
 * Addition.
 */
inline
Spectrum Spectrum::operator+(const Spectrum& other) const
{
	return Spectrum(r + other.r, g + other.g, b + other.b);
}


/*
 * Subtraction.
 */
inline
Spectrum Spectrum::operator-(const Spectrum& other) const 
{
	return Spectrum(r - other.r, g - other.g, b - other.b);
}


/*
 * Accumulated scalar multiplication.
 */
inline
Spectrum& Spectrum::operator*=(const float s)
{
	r *= s;
	g *= s;
	b *= s;
	return *this;
} 


/*
 * Accumulated scalar division.
 */
inline
Spectrum& Spectrum::operator/=(const float s)
{
	float inv = 1.f / s;
	r *= inv;
	g *= inv;
	b *= inv;
	return *this;
}


/*
 * Accumulated addition.
 */
inline
Spectrum& Spectrum::operator+=(const Spectrum& other)
{
	r += other.r;
	g += other.g;
	b += other.b;
	return *this;
}


/*
 * Accumulated subtraction.
 */
inline
Spectrum& Spectrum::operator-=(const Spectrum& other)
{
	r -= other.r;
	g -= other.g;
	b -= other.b;
	return *this;
}


/*
 * Clamp the r,g and b components between 0.f and 1.f.
 */
inline
void Spectrum::clamp(void)
{
	r = r > 0.f ? (r < 1.f ? r : 1.f) : 0.f;
	g = g > 0.f ? (g < 1.f ? g : 1.f) : 0.f;
	b = b > 0.f ? (b < 1.f ? b : 1.f) : 0.f;
}


#endif // _SPECTRUM_H_
