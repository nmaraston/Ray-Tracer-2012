#ifndef _VECTOR_OPS_H_
#define _VECTOR_OPS_H_


#include "Vector.h"


// Dot product.
template <class T, unsigned SIZE>
T dot_product(const Vector<T, SIZE>& v, const Vector<T, SIZE>& w);

// Cross product.
// Only defined for 3-dimensional vectors.
template <class T, unsigned SIZE>
Vector<T, SIZE> cross_product(const Vector<T, SIZE>& v, const Vector<T, SIZE>& w);

// Include function implementations.
#include "vector_ops.cpp"

#endif // _VECTOR_OPS_H_
