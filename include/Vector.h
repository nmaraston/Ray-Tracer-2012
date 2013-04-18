#ifndef _VECTOR_H_
#define _VECTOR_H_


#include <math.h>
#include <assert.h>


template <class T, unsigned SIZE>
class Vector {
	
	public:
		
		// Default Constructor. Creates a zero vector with size SIZE.
		inline Vector();
	
		// Constructs vectors with the given parameters. Sizes must be appropriate.
		inline Vector(T a, T b);
		inline Vector(T a, T b, T c);
		inline Vector(T a, T b, T c, T d);

		// Copy constructor.
		inline Vector(const Vector<T, SIZE>& v);

	
		// Assignment operator.
		inline Vector<T, SIZE>& operator=(const Vector<T, SIZE>& rhs);


		// Read only reference to this vector's i'th entry.
		inline const T& operator()(unsigned i) const;
		// Read/write reference to this vector's i'th entry.
		inline T& operator()(unsigned i); 


		//  MATHEMATICAL OPERATIONS

		// Equality.
		bool operator==(const Vector<T, SIZE>& v) const;

		// Unary minus. Returns new vector.
		Vector<T, SIZE> operator-() const;
		
		// Scalar multiplication.
		template <class U, unsigned S, class ST> 
		friend Vector<U, S> operator*(const ST s, const Vector<U, S>& v);
		template <class U, unsigned S, class ST> 
		friend Vector<U, S> operator*(const Vector<U, S>& v, const ST s);

		// Scalar division.
		Vector<T, SIZE> operator/(const T s) const;

		// Vector addition and subtraction. Returns new vector.
		Vector<T, SIZE> operator+(const Vector<T, SIZE>& v) const;
		Vector<T, SIZE> operator-(const Vector<T, SIZE>& v) const;

		// Accumulated scalar multiplication and division. Return *this.
		Vector<T, SIZE>& operator*=(const T s);
		Vector<T, SIZE>& operator/=(const T s);

		// Accumulated vector addition and subtraction. Returns *this.
		Vector<T, SIZE>& operator+=(const Vector<T, SIZE>& v);
		Vector<T, SIZE>& operator-=(const Vector<T, SIZE>& v);

		// Normalization and magnitude.
		inline Vector<T, SIZE>& normalize();
		inline T magnitude();
		T squared_magnitude();

	private:
		
		T components_[SIZE];
};


// Inline implementations:


/*
 * Default constructor. Creates a zero vector of size SIZE.
 */
template <class T, unsigned SIZE>
inline
Vector<T, SIZE>::Vector()
{
	for (unsigned i = 0; i < SIZE; ++i) {
		components_[i] = 0;
	}
}


/* 
 * Creates a vector of the form (a, b). Must be of size 2.
 */
template <class T, unsigned SIZE>
inline
Vector<T, SIZE>::Vector(T a, T b)
{
	assert(SIZE == 2);
	
	components_[0] = a;
	components_[1] = b;
}


/*
 * Creates of a vector of the form (a, b, c). Must be of size 3.
 */
template <class T, unsigned SIZE>
inline
Vector<T, SIZE>::Vector(T a, T b, T c)
{
	assert(SIZE == 3);
		
	components_[0] = a;
	components_[1] = b;
	components_[2] = c;
}


/*
 * Creates a vector of the form (a, b, c, d). Must be of size 4.
 */
template <class T, unsigned SIZE>
inline
Vector<T, SIZE>::Vector(T a, T b, T c, T d)
{
	assert(SIZE == 4);
	
	components_[0] = a;
	components_[1] = b;
	components_[2] = c;
	components_[3] = d;
}


/*
 * Copy constructor.
 */
template <class T, unsigned SIZE>
inline
Vector<T, SIZE>::Vector(const Vector<T, SIZE>& v)
{
	for (unsigned i = 0; i < SIZE; ++i) {
		components_[i] = v(i);
	}
}


/*
 * Assignment operator. Returns *this.
 */
template <class T, unsigned SIZE>
inline
Vector<T, SIZE>& Vector<T, SIZE>::operator=(const Vector<T, SIZE>& rhs)
{
	for (unsigned i = 0; i < SIZE; ++i) {
		components_[i] = rhs(i);
	}
	return *this;
}


/*
 * Read only reference.
 */
template <class T, unsigned SIZE>
inline
const T& Vector<T, SIZE>::operator()(unsigned i) const
{
	assert(i < SIZE);
	return components_[i];
}


/*
 * Read/write reference.
 */
template <class T, unsigned SIZE>
inline
T& Vector<T, SIZE>::operator()(unsigned i)
{
	assert(i < SIZE);
	return components_[i];
}


/*
 * normalize this vector with the standard 2-norm. Returns *this.
 */
template <class T, unsigned SIZE>
inline
Vector<T, SIZE>& Vector<T, SIZE>::normalize()
{
	return (*this) /= magnitude();
}


/*
 * Return the magnitude of this vector using the standard 2-norm.
 */
template <class T, unsigned SIZE>
T Vector<T, SIZE>::magnitude()
{
	return sqrt(squared_magnitude());
}


// Including the rest of the Vector implementation for template support.
#include "VectorImp.h"


// Some helper types.
typedef Vector<short, 2> Vector2s;
typedef Vector<short, 3> Vector3s;
typedef Vector<short, 4> Vector4s;
typedef Vector<int, 2> Vector2i;
typedef Vector<int, 3> Vector3i;
typedef Vector<int, 4> Vector4i;
typedef Vector<double, 2> Vector2d;
typedef Vector<double, 3> Vector3d;
typedef Vector<double, 4> Vector4d;


#endif // _VECTOR_H_
