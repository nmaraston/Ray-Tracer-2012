#include <assert.h>
#include <math.h>

// Vector class implementation.

/*
 * Constructor.
 * Allocates memory for a vector of the given size and zeros out memory (zero vector).
 */
template <class T>
Vector<T>::Vector(unsigned size)
	: size_(size), components_(0)
{
	if (size_) {
		alloc_components();
		for (unsigned i = 0; i < size_; ++i) {
			(*this)(i) = 0;
		}
	}
}


/*
 * Copy constructor.
 */
template <class T>
Vector<T>::Vector(const Vector<T> &v)
{
	size_ = v.size();
	if (size_) {
		alloc_components();
		for (unsigned i = 0; i < size_; ++i) {
			(*this)(i) = 0;
		}
	}
} 


/*
 * Destructor.
 */
template <class T>
Vector<T>::~Vector()
{
	free_components();
}


/*
 * Assignment operator.
 * Vectors must be of the same size.
 */
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T> &v)
{
	assert(size_ == v.size());
	for (unsigned i = 0; i < size_; ++i) {
		(*this)(i) = v(i);
	}
	return *this;
}


// Implementation of mathamatical operations.

/*
 * Vector equality.
 */
template <class T>
bool Vector<T>::operator==(const Vector<T> &v)
{
	if (size_ == v.size()) {
		return false;
	}

	for (unsigned i = 0; i < size_; ++i) {
		if ((*this)(i) != v(i)) {
			return false;
		}
	}

	return true;
}


/*
 * Unary minus.
 */
template <class T>
Vector<T> Vector<T>::operator-()
{
	Vector<T> result(size_);
	for (unsigned i = 0; i < size_; ++i) {
		result(i) = -(*this)(i);
	}
	return result;
}


/*
 * Scalar multiplication.
 */
template <class U>
Vector<U> operator*(const U s, const Vector<U> &v)
{
	Vector<U> result(v.size_);
	for (unsigned i = 0; i < v.size_; ++i) {
		result(i) = s * v(i);
	}
	return result;
}

template <class U>
Vector<U> operator*(const Vector<U> &v, const U s)
{
	return s * v;
}


/*
 * Scalar division.
 */
template <class T>
Vector<T> Vector<T>::operator/(const T s)
{
	assert(s != 0);

	Vector<T> result(size_);
	for (unsigned i = 0; i < size_; ++i) {
		result(i) = (*this)(i) / s;
	}
	return result;
}


/*
 * Accumulated scalar multiplication.
 */
template <class T>
Vector<T>& Vector<T>::operator*=(const T s)
{
	for (unsigned i = 0; i < size_; ++i) {
		(*this)(i) *= s;
	}
	return *this;
}


/*
 * Accumulated scalar division.
 */
template <class T>
Vector<T>& Vector<T>::operator/=(const T s)
{
	assert(s != 0);

	for (unsigned i = 0; i < size_; ++i) {
		(*this)(i) /= s;
	}
	return *this;
}
	


/*
 * Vector addition.
 */
template <class T>
Vector<T> Vector<T>::operator+(const Vector<T> &v)
{
	assert(size_ == v.size());

	Vector<T> result(size_);
	for (unsigned i = 0; i < size_; ++i) {
		result(i) = (*this)(i) + v(i);
	}
	return result;
}


/*
 * Vector subtraction.
 */
template <class T>
Vector<T> Vector<T>::operator-(const Vector<T> &v)
{
	assert(size_ == v.size());
	
	Vector<T> result(size_);
	for (unsigned i = 0; i < size_; ++i) {
		result(i) = (*this)(i) - v(i);
	}
	return result;
}


/*
 * Accumulated vector addition.
 */
template <class T>
Vector<T>& Vector<T>::operator+=(const Vector<T> &v)
{
	assert(size_ == v.size());
	
	Vector<T> result(size_);
	for (unsigned i = 0; i < size_; ++i) {
		(*this)(i) += v(i);
	}
	return *this;
}


/*
 * Accumulated vector subtraction.
 */
template <class T>
Vector<T>& Vector<T>::operator-=(const Vector<T> &v)
{
	assert(size_ == v.size());
	
	Vector<T> result(size_);
	for (unsigned i = 0; i < size_; ++i) {
		(*this)(i) -= v(i);
	}
	return *this;
}


/*
 * Return the squared magnitude of this vector using the standard 2-norm.
 */
template <class T>
T Vector<T>::squared_magnitude()
{
	T result = 0;
	for (unsigned i = 0; i < size_; ++i) {
		result += (*this)(i) * (*this)(i);
	}
	return result;
}

