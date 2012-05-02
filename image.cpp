#include "image.h"	
#include <iostream>
#include <fstream>


// Image class implementation.

/*
 * Empty image constructor. Allocates memory for an image of the given size. Does NOT zero out 
 * memory.
 */
template <class T>
image<T>::image(unsigned rows, unsigned columns, unsigned channels)
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
image<T>::image(const char* filename)
	: nrows_(0), ncols_(0), nchans_(0)
{
	load(filename);
}


/*
 * Destructor.
 */
template <class T>
image<T>::~image()
{
	free_pixels();
}


/*
 * Destructable resize. Deallocs and reallocs.
 */
template <class T>
void image<T>::set_size(unsigned rows, unsigned columns, unsigned channels)
{
	free_pixels();
	
	nrows_ = rows;
	ncols_ = columns;
	nchans_ = channels;
	
	alloc_pixels();
}


/*
 * Dynamically allocates memory for image.
 */
template <class T>
void image<T>::alloc_pixels()
{	
	// Alloc rows.
	pixels_ = new T[nrows_ * ncols_ * nchans_];

	// TODO: Handle allocating exceptions.
}


/*
 * Free memory that was previously allocated for image.
 */
template <class T>
void image<T>::free_pixels()
{
	delete[] pixels_;

	// TODO: Handle deleting exceptions.
}


/*
 * Saving image with PPM format. Depending upon the number of channels, formats PPM and PGM format 
 * are used. Also, Binary formats are used, that is, magic numbers P5 for grayscale images and P6 
 * for RGB images.
 */
template <class T>
void image<T>::save_ppm(const char* filename)
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
void image<T>::load(const char* filename)
{
	// TODO: Implement image loading.
}

