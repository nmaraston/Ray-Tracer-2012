#include <assert.h>


// Vector class implementation:

// Implementation of matematical operations.


/*
 * Vector equality. 
 */
template <class T, unsigned SIZE>
bool Vector<T, SIZE>::operator==(const Vector<T, SIZE>& v) const
{
	for (unsigned i = 0; i < SIZE; ++i) {
		if ((*this)(i) != v(i)) {
			return false;
		}
	}
	
	return true;
}


/*
 * Unary minus.
 */
template <class T, unsigned SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator-()
{
	Vector<T, SIZE> result;
	for (unsigned i = 0; i < SIZE; ++i) {
		result(i) = -(*this)(i);
	}
	return result;
}


/*
 * Scalar multiplication.
 */
template <class U, unsigned S, class ST>
Vector<U, S> operator*(const ST s, const Vector<U, S>& v)
{
	Vector<U, S> result;
	for (unsigned i = 0; i < S; ++i) {
		result(i) = s * v(i);
	}
	return result;
}

template <class U, unsigned S, class ST>
Vector<U, S> operator*(const Vector<U, S>& v, const ST s)
{
	Vector<U, S> result;
	for (unsigned i = 0; i < S; ++i) {
		result(i) = s * v(i);
	}
	return result;
}


/*
 * Scalar division.
 */
template <class T, unsigned SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator/(const T s) const
{
	assert(s != 0);

	Vector<T, SIZE> result;
	for (unsigned i = 0; i < SIZE; ++i) {
		result(i) = (*this)(i) / s;
	}
	return result;
}


/*
 * Vector addition.
 */
template <class T, unsigned SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator+(const Vector<T, SIZE>& v) const
{
	Vector<T, SIZE> result;
	for (unsigned i = 0; i < SIZE; ++i) {
		result(i) = (*this)(i) + v(i);
	}
	return result;
}


/*
 * Vector subtraction.
 */
template <class T, unsigned SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator-(const Vector<T, SIZE>& v) const
{
	Vector<T, SIZE> result;
	for (unsigned i = 0; i < SIZE; ++i) {
		result(i) = (*this)(i) - v(i);
	}
	return result;
}


/*
 * Accumulated scalar multiplication. Returns *this.
 */
template <class T, unsigned SIZE>
Vector<T, SIZE>& Vector<T, SIZE>::operator*=(const T s)
{
	for (unsigned i = 0; i < SIZE; ++i) {
		(*this)(i) *= s;
	}
	return *this;
}


/*
 * Accumulated scalar division. Returns *this.
 */
template <class T, unsigned SIZE>
Vector<T, SIZE>& Vector<T, SIZE>::operator/=(const T s)
{
	for (unsigned i = 0; i < SIZE; ++i) {
		(*this)(i) /= s;
	}
	return *this;
}


/*
 * Accumulated vector addition. Returns *this.
 */
template <class T, unsigned SIZE>
Vector<T, SIZE>& Vector<T, SIZE>::operator+=(const Vector<T, SIZE>& v)
{
	Vector<T, SIZE> result;
	for (unsigned i = 0; i < SIZE; ++i) {
		(*this)(i) += v(i);
	}
	return *this;
}


/*
 * Accumulated vector subtraction. Returns *this.
 */
template <class T, unsigned SIZE>
Vector<T, SIZE>& Vector<T, SIZE>::operator-=(const Vector<T, SIZE>& v)
{
	Vector<T, SIZE> result;
	for (unsigned i = 0; i < SIZE; ++i) {
		(*this) -= v(i);
	}
	return *this;
}


/* 
 * Return the squared magnitude of this vector using the standard 2-norm.
 */
template <class T, unsigned SIZE>
T Vector<T, SIZE>::squared_magnitude()
{
	T result = 0;
	for (unsigned i = 0; i < SIZE; ++i) {
		result += (*this)(i) * (*this)(i);
	}
	return result;
}
