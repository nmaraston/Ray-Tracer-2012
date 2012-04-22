#ifndef _VECTOR_H_
#define _VECTOR_H_


template <class T>
class Vector {
	
	public:
		
		// Constructors.
		
		// Create a zero vector of the given size.
		Vector(unsigned size = 0);
	
		// Destructor.
		~Vector();

		
		// Read only reference to this vectors i'th entry.
		inline T const& operator()(unsigned i);
		// Read/write reference to this vectors i'th entry.
		inline T& operator()(unsigned i);


		// Destructable resize.
		void set_size(unsigned n);
		
		// Getter for dimension.
		inline unsigned size();

	
		// Vector operations:

		inline Vector<T>& operator*(T s);  // Scalar multiplication
		inline Vector<T>& operator/(T s);  // Scalar division.

		inline Vector<T>& operator+=(Vector<T> const&v);  // Scalar addition.
		inline Vector<T>& operator-=(Vector<T> const&v);  // Scalar subtraction.

		inline Vector<T> operator+(Vector<T> const &v);  // Vector addition.
		inline Vector<T> operator-(Vector<T> const &v);  // Vector subtraction.

	private:

		// Vector dimension.
		unsigned size_;

		// Vector components.
		T* components_;

		// Memory management.
		void alloc_components();
		void free_components();
};


/*
 * Vector class implementation.
 */

/*
 * Zero vector constructor. Allocates memory for a vector of the given size and zeros out memory.
 */
template <class T>
Vector<T>::Vector(unsigned size)
	: size_(size)
{
	alloc_components();

	for (int i = 0; i < size; ++i) {
		(*this)(i) = 0;
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
 * Read only component access.
 */
template <class T>
inline
T const& Vector<T>::operator()(unsigned i) const
{
	// TODO: Validate arguments.
	return components_[i];
}


/*
 * Read/write component access.
 */
template <class T>
inline
T& Vector<T>::operator()(unsigned i)
{
	// TODO: Validate arguments.
	return components_[i];
}


/*
 * Destrucable resize.
 */
template <class T>
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
unsigned Vector<T>size()
{
	return size_;
}


/*
 * Memory allocator for vector components.
 */
template <class T>
void Vector<T>::alloc_components()
{
	components_ = new T[size_];
}


/*
 * Memory de-allocator for vector components.
 */
template <class T>
void Vector<T>::free_components()
{
	delete[] components_;
}
	

#endif // _VECTOR_H_

