#include <assert.h>


// Implementation of all vector operations.


/*
 * Standard dot product.
 */
template <class T, unsigned SIZE>
T dot_product(const Vector<T, SIZE>& v, const Vector<T, SIZE>& w)
{
	T result = 0;
	for (unsigned i = 0; i < SIZE; ++i) {
		result += v(i) * w(i);
	}
	return result;
}


/*
 * Cross product. Only defined for 3-dimensional vectors.
 */
template <class T, unsigned SIZE>
Vector<T, SIZE> cross_product(const Vector<T, SIZE>& v, const Vector<T, SIZE>& w)
{
	assert(SIZE == 3);

	Vector<T, 3> result;

	result(0) = (v(1) * w(2)) - (w(1) * v(2));
	result(1) = (v(2) * w(0)) - (w(2) * v(0));
	result(2) = (v(0) * w(1)) - (w(0) * v(1));
	
	return result;
}

