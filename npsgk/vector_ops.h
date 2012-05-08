#ifndef _VECTOR_OPS_H_
#define _VECTOR_OPS_H_


#include "Vector.h"

// Dot product.
template <class T>
T dot_product(const Vector<T> &v, const Vector<T> &w);

// Cross product.
// Only defined for 3-dimensional vectors.
template <class T>
Vector<T> cross_product(const Vector<T> &v, const Vector<T> &w);

// Include function implementations.
#include "vector_ops.cpp"

#endif // _VECTOR_OPS_H_
