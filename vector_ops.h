#ifndef _VECTOR_OPS_H_
#define _VECTOR_OPS_H_


#include "vector.h"

/*
 * All vector operations are defined in this header. 
 */


// Vector eqaulity.
template <class T>
bool operator==(vector<T> const &v, vector<T> const &w);

// Scalar multiplication: s * v = v * s.
template <class T>
vector<T> operator*(T s, vector<T> const &v);
template <class T>
vector<T> operator*(vector<T> const &v, T s);

// Scalar division: v / s.
template <class T>
vector<T> operator/(vector<T> const &v, T s);

// Vector addition: v + w.
template <class T>
vector<T> operator+(vector<T> const &v, vector<T> const &w);

// Vector subtraction: v - w.
template <class T>
vector<T> operator-(vector<T> const &v, vector<T> const &w);

// Accumulated vector addition: v += w. Returns the first argument.
template <class T>
vector<T> operator+=(vector<T> &v, vector<T> const &w);

// Accumulated vector subtraction. v += w. Returns the first argument.
template <class T>
vector<T> operator-=(vector<T> &v, vector<T> const &w);

// Dot product.
template <class T>
T dot_product(vector<T> const &v, vector<T> const &w);

// Include function implementations.
#include "vector_ops.cpp"

#endif // _VECTOR_OPS_H_
