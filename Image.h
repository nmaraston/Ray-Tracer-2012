#ifndef _IMAGE_H_
#define _IMAGE_H_


#include <assert.h>


typedef unsigned char byte; 


/* 
 * Basic Image class. 
 * This class implements functionality for storing and accessing images in memory. Image access is 
 * offsetted from the bottom left corner. That is, pixel (0, 0) corresponds to the bottom left 
 * corner of the image.
 */
template <class T>
class Image {

	public:
	
		// Constructors.
	
		// Creates an empty image of the given size. Memory is NOT zeroed out.
		Image(unsigned rows = 0, unsigned columns = 0, unsigned channels = 0);
	
		// Equivalent to calling: image = Image() followed by image.load(filename).
		Image(const char* filename);

		// Destructor.
		~Image();


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
T const& Image<T>::operator()(unsigned row, unsigned column, unsigned channel) const
{
	assert(row < nrows_);
	assert(column < ncols_);
	assert(channel < nchans_);
	return pixels_[ nchans_ * ((nrows_ - row) * ncols_ + column) + channel ];
}


/*
 * Read/write pixel access.
 */
template <class T>
inline 
T& Image<T>::operator()(unsigned row, unsigned column, unsigned channel)
{
	assert(row < nrows_);
	assert(column < ncols_);
	assert(channel < nchans_);
	return pixels_[ nchans_ * ((nrows_ - row - 1) * ncols_ + column) + channel ];	
}


/*
 * Get row count.
 */
template <class T>
inline 
unsigned Image<T>::rows()
{
	return nrows_;
}


/*
 * Get column count.
 */
template <class T>
inline 
unsigned Image<T>::columns()
{
	return ncols_;
}


// Include the rest of the image class implementation.
#include "Image.cpp"


#endif // _IMAGE_H_

