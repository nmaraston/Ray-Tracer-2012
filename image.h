#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <iostream>
#include <fstream>

typedef unsigned char byte; 

/* 
 * Basic image class. This class implements functionality for storing and accessing images in 
 * memory. It is independent of any specific image format. 
 */
template <class T>
class Image {

	public:
	
		//Constructors.
	
		// Creates an empty image of the given size. Memory is NOT zeroed out.
		Image(unsigned rows = 0, unsigned columns = 0, unsigned channels = 0);
	
		// Equivalent to calling: image = Image() followed by image.load(filename).
		Image(const char* filename);

		// Destructor.
		~Image();


		// Read only reference to pixel at coordinate row, column in channel c.
		T const& operator()(unsigned row, unsigned column, unsigned channel) const;
		// Read/write reference to pixel at coordinate row, column in channel c.
		T& operator()(unsigned row, unsigned column, unsigned channel);

		// Destructable resize.
		void set_size(unsigned rows, unsigned columns, unsigned channels);

		// Getters for dimensions.
		unsigned rows();
		unsigned columns();
 

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
		T *pixels_;

		// Memory management.
		void alloc_pixels();
		void free_pixels();	
};


/*
 * Image class implementation.
 */

/*
 * Empty image constructor. Allocates memory for an image of the given size. Does NOT zero out 
 * memory.
 */
template <class T>
Image<T>::Image(unsigned rows, unsigned columns, unsigned channels)
	: nrows_(rows), ncols_(columns), nchans_(channels)
{
	alloc_pixels();
}


/*
 * Construct new image object from a image file on disk. The inheriting class is responsible for 
 * how the image is loaded.
 * 
 * This is equivalent to calling: image = Image() followed by image.load(filename).
 */
template <class T>
Image<T>::Image(const char* filename)
	: nrows_(0), ncols_(0), nchans_(0)
{
	load(filename);
}


/*
 * Destructor.
 */
template <class T>
Image<T>::~Image()
{
	free_pixels();
}


/*
 * Read only pixel access.
 */
template <class T>
inline
T const& Image<T>::operator()(unsigned row, unsigned column, unsigned channel) const
{
	// TODO: Validate arguments.
	return pixels_[ nchans_ * (row * ncols_ + column) + channel ];
}


/*
 * Read/write pixel access.
 */
template <class T>
inline 
T& Image<T>::operator()(unsigned row, unsigned column, unsigned channel)
{
	// TODO: Validate arguments.
	return pixels_[ nchans_ * (row * ncols_ + column) + channel ];	
}


/*
 * Destructable resize. Deallocs and reallocs.
 */
template <class T>
void Image<T>::set_size(unsigned rows, unsigned columns, unsigned channels)
{
	free_pixels();
	
	nrows_ = rows;
	ncols_ = columns;
	nchans_ = channels;
	
	alloc_pixels();
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


/*
 * Dynamically allocates memory for image.
 */
template <class T>
void Image<T>::alloc_pixels()
{	
	// Alloc rows.
	pixels_ = new T[nrows_ * ncols_ * nchans_];

	// TODO: Handle dem allocing exceptions.
}


/*
 * Free memory that was previously allocated for image.
 */
template <class T>
void Image<T>::free_pixels()
{
	delete[] pixels_;

	// TODO: Handle dem deleting exceptions.
}


/*
 * Saving image with PPM format. Depending upon the number of channels, formats PPM and PGM format. 
 * Binary formats are used, that is, magic numbers P5 for grayscale images and P6 for RGB images.
 */
template <class T>
void Image<T>::save_ppm(const char* filename)
{
	std::ofstream file;

	file.open(filename, std::ios::binary);
	if (!file)
	{
		// TODO: Handle open error. Does it throw an exception?
 	}

	// Magic number. P5 for grayscale, P6 for RGB.
	switch (nchans_) {
		case 1:
			file << "P5" << std::endl;
			break;
		case 3: 
			file << "P6" << std::endl;
			break;
		default:
			// TODO: Invalid image format. Throw exception.
			break;
	}

	// Width and height.
	file << ncols_ << " " << nrows_ << std::endl;

	// Maximum colour value. Always 255.
	file << "255" << std::endl;

	// Write pixel values. 
	for (int i = 0; i < nrows_; ++i) {
		for (int j = 0; j < ncols_; ++j) {
			for (int c = 0; c < nchans_; ++c) {	
				file << (*this)(i,j,c);;
			}
		}
	}

	file.close();
}


/*
 * Currently only supports reading PPM image format.
 */
template <class T>
void Image<T>::load(const char* filename)
{
	// TODO: Implement image loading.
}


#endif // _IMAGE_H_

