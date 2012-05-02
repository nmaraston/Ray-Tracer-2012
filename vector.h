#ifndef _VECTOR_H_
#define _VECTOR_H_


template <class T>
class vector {
	
	public:
		
		// Constructor. Create a zero vector of the given size.
		vector(unsigned size = 0);

		// Copy constructor.
		vector(const vector<T> &v);
	
		// Destructor.
		~vector();


		// Assignment operator.
		inline vector<T>& operator=(const vector<T> &v);	
	
	
		// Read only reference to this vectors i'th entry.
		inline T const& operator()(unsigned i) const;
		// Read/write reference to this vectors i'th entry.
		inline T& operator()(unsigned i);


		// Destructable resize.
		inline void set_size(unsigned n);
		
		// Getter for dimension.
		inline unsigned size() const;

	private:

		// Vector dimension.
		unsigned size_;

		// Vector components.
		T* components_;

		// Memory management.
		inline void alloc_components();
		inline void free_components();
		void deep_copy(const vector<T> &v);
};


// Inline implementations.

/*
 * Read only component access.
 */
template <class T>
inline
T const& vector<T>::operator()(unsigned i) const
{
	// TODO: Validate arguments.
	return components_[i];
}


/*
 * Read/write component access.
 */
template <class T>
inline
T& vector<T>::operator()(unsigned i)
{
	// TODO: Validate arguments.
	return components_[i];
}


/*
 * Destrucable resize.
 */
template <class T>
inline
void vector<T>::set_size(unsigned size)
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
unsigned vector<T>::size() const
{
	return size_;
}


/*
 * Memory allocator for vector components.
 */
template <class T>
inline
void vector<T>::alloc_components()
{
	components_ = new T[size_];
}


/*
 * Memory de-allocator for vector components.
 */
template <class T>
inline
void vector<T>::free_components()
{
	if (components_ != 0) {
		delete[] components_;
		components_ = 0;
	}
}

// Include the rest of the implementation for template support.
#include "vector.cpp"


#endif // _VECTOR_H_
