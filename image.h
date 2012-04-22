#ifndef _IMAGE_H_
#define _IMAGE_H_


typedef unsigned char byte; 

/* 
 * Basic image class. This class implements functionality for storing and accessing images in 
 * memory.
 */
template <class T>
class image {

	public:
	
		// Constructors.
	
		// Creates an empty image of the given size. Memory is NOT zeroed out.
		image(unsigned rows = 0, unsigned columns = 0, unsigned channels = 0);
	
		// Equivalent to calling: image = Image() followed by image.load(filename).
		image(const char* filename);

		// Destructor.
		~image();


		// Read only reference to pixel at coordinate row, column in channel c.
		inline T const& operator()(unsigned row, unsigned column, unsigned channel) const;
		// Read/write reference to pixel at coordinate row, column in channel c.
		inline T& operator()(unsigned row, unsigned column, unsigned channel);

		// Destructable resize.
		void set_size(unsigned rows, unsigned columns, unsigned channels);

		// Getters for dimensions.
		inline unsigned rows();
		inline unsigned columns();
 

		// Format depenent:
	
		// Loading and saving with PPM format.
		void load(const char* filename);
		void save_ppm(const char* filename);

	private:
		
		// Image dimensions.
		unsigned nrows_;
		unsigned ncols_;
		unsigned nchans_;

		// 3D array to pixels sorted into channels.
		T* pixels_;

		// Memory management.
		void alloc_pixels();
		void free_pixels();	
};


/*
 * Inline implimentations:
 */

/*
 * Read only pixel access.
 */
template <class T>
inline
T const& image<T>::operator()(unsigned row, unsigned column, unsigned channel) const
{
	// TODO: Validate arguments.
	return pixels_[ nchans_ * (row * ncols_ + column) + channel ];
}


/*
 * Read/write pixel access.
 */
template <class T>
inline 
T& image<T>::operator()(unsigned row, unsigned column, unsigned channel)
{
	// TODO: Validate arguments.
	return pixels_[ nchans_ * (row * ncols_ + column) + channel ];	
}


/*
 * Get row count.
 */
template <class T>
inline 
unsigned image<T>::rows()
{
	return nrows_;
}


/*
 * Get column count.
 */
template <class T>
inline 
unsigned image<T>::columns()
{
	return ncols_;
}


// Include the rest of the image class implementation.
#include "image.cpp"


#endif // _IMAGE_H_

