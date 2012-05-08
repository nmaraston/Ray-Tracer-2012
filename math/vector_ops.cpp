#include <assert.h>

// Implementation of all vector operations.


/*
 * Standard dot product.
 */
template <class T>
T dot_product(const Vector<T> &v, const Vector<T> &w)
{
	assert(v.size() == w.size());	

	T result = 0;

	for (unsigned i = 0; i < v.size(); ++i) {
		result += v(i) * w(i);
	}
	
	return result;
}


/*
 * Cross product. Only defined for 3-dimensional vectors.
 */
template <class T>
Vector<T> cross_product(const Vector<T> &v, const Vector<T> &w)
{
	assert(v.size() == 3 && w.size() == 3);

	Vector<T> result(3);
	
	result(0) = (v(1) * w(2)) - (w(1) * v(2));
	result(1) = (v(2) * w(0)) - (w(2) * v(0));
	result(2) = (v(0) * w(1)) - (w(0) * v(1));
	
	return result;
}

