#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <assert.h>

template <class T>
class Vector {
	
	public:
		
		// Constructor. Create a zero vector of the given size.
		Vector(unsigned size = 0);

		// Copy constructor.
		Vector(const Vector<T> &v);
	
		// Destructor.
		~Vector();


		// Assignment operator.
		inline Vector<T>& operator=(const Vector<T> &v);	
	
	
		// Read only reference to this vectors i'th entry.
		inline T const& operator()(unsigned i) const;
		// Read/write reference to this vectors i'th entry.
		inline T& operator()(unsigned i);


		// Destructable resize.
		inline void set_size(unsigned n);		
		// Getter for dimension.
		inline unsigned size() const;


		// Mathamatical operations.
		
		// Eqaulity.
		bool operator==(const Vector<T> &v);

		// Unary minus. Returns new vector.
		Vector<T> operator-();

		// Scalar multiplication and division. Returns new vector.
		template <class U> friend Vector<U> operator*(const U s, const Vector<U> &v);
		template <class U> friend Vector<U> operator*(const Vector<U> &v, const U s);
		Vector<T> operator/(const T s);

		// Accumulated scalar multiplication and division. Returns *this.
		Vector<T>& operator*=(const T s);
		Vector<T>& operator/=(const T s);

		// Vector addition and subtraction. Returns new vector.
		Vector<T> operator+(const Vector<T> &v);
		Vector<T> operator-(const Vector<T> &v);

		// Accumulated vector addition and subtraction. Returns *this.
		Vector<T>& operator+=(const Vector<T> &v);
		Vector<T>& operator-=(const Vector<T> &v);
		
		// Normalization and magnitude.
		inline Vector<T>& normalize();
		inline T magnitude();
		T squared_magnitude();

	private:

		// Vector dimension.
		unsigned size_;

		// Vector components.
		T* components_;

		// Memory management.
		inline void alloc_components();
		inline void free_components();
};


// Inline implementations.

/*
 * Read only component access.
 */
template <class T>
inline
T const& Vector<T>::operator()(unsigned i) const
{
	assert(i < size_);
	return components_[i];
}


/*
 * Read/write component access.
 */
template <class T>
inline
T& Vector<T>::operator()(unsigned i)
{
	assert(i < size_);
	return components_[i];
}


/*
 * Destrucable resize.
 */
template <class T>
inline
void Vector<T>::set_size(unsigned size)
{
	free_components();
	size_ = size;
	alloc_components();
}


/*
 * Get size.
 */
template <class T>
inline
unsigned Vector<T>::size() const
{
	return size_;
}


/*
 * Memory allocator for vector components.
 */
template <class T>
inline
void Vector<T>::alloc_components()
{
	components_ = new T[size_];
}


/*
 * Memory de-allocator for vector components.
 */
template <class T>
inline
void Vector<T>::free_components()
{
	if (components_ != 0) {
		delete[] components_;
		components_ = 0;
	}
	size_ = 0;
}


/*
 * Normalize this vector with the standard 2-norm. Returns *this.
 */
template <class T>
inline
Vector<T>& Vector<T>::normalize()
{
	return (*this) /= magnitude();
}


/*
 * Return the magnitude of this vector using the standard 2-norm.
 */
template <class T>
T Vector<T>::magnitude()
{
	return sqrt(squared_magnitude());
}


// Some helper types.
typedef Vector<short> Vector_s;
typedef Vector<int> Vector_i;
typedef Vector<float> Vector_f;
typedef Vector<double> Vector_d;


// Include the rest of the implementation for template support.
#include "Vector.cpp"


#endif // _VECTOR_H_
