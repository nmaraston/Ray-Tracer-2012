#ifndef _VECTOR_OPS_H_
#define _VECTOR_OPS_H_


#include "vector.h"

/*
 * All vector operations are defined in this header. 
 */


// Vector eqaulity.
template <class T>
bool operator==(const vector<T> &v, const vector<T> &w);

// Scalar multiplication: s * v = v * s.
template <class T>
vector<T> operator*(T s, const vector<T> &v);
template <class T>
vector<T> operator*(const vector<T> &v, T s);

// Scalar division: v / s.
template <class T>
vector<T> operator/(const vector<T> &v, T s);

// Vector addition: v + w.
template <class T>
vector<T> operator+(const vector<T> &v, const vector<T> &w);

// Vector subtraction: v - w.
template <class T>
vector<T> operator-(const vector<T> &v, const vector<T> &w);

// Accumulated vector addition: v += w. Returns a reference to the first argument.
template <class T>
vector<T>& operator+=(vector<T> &v, const vector<T> &w);

// Accumulated vector subtraction. v -= w. Returns a reference to the first argument.
template <class T>
vector<T>& operator-=(vector<T> &v, const vector<T> &w);

// Dot product.
template <class T>
T dot_product(const vector<T> &v, const vector<T> &w);

// Include function implementations.
#include "vector_ops.cpp"

#endif // _VECTOR_OPS_H_
