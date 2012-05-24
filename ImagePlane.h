#ifndef _IMAGE_PLANE_H_
#define _IMAGE_PLANE_H_


#include <assert.h>


/*
 * An image plane defines the dimensions and resolution of the image to be rendererd.
 */
struct ImagePlane {
	
	public:
		
		// Constructs a symetric image plane.
		inline ImagePlane(double width, double height, unsigned hres, unsigned vres);

		// Constructs an image plane with the given parameters.
		inline ImagePlane(double left, double right, double bottom, double top, 
						   unsigned hres, unsigned vres); 

		// Image dimensions.
		double width;
		double height;

		// Image edges.
		double left;
		double right;
		double bottom;
		double top;

		// Image resolutions.
		unsigned hres;
		unsigned vres;

};


// Inline implementations:


/*
 * Constructs a symetric image plane with the given width, height and resolution parameters.
 * Symetry implies left == -right and bottom == -top.
 */
inline
ImagePlane::ImagePlane(double _width, double _height, unsigned _hres, unsigned _vres)
	:	width(_width), height(_height), 
		left(-_width/2), right(_width/2), bottom(-_height/2), top(_height/2), 
		hres(_hres), vres(_vres)	
{}


/*
 * Constructs an image plane with the given parameters.  
 */
inline
ImagePlane::ImagePlane(double left, double right, double bottom, double top, 
						 unsigned _hres, unsigned _vres)
	:	width(right - left), height(top - bottom), 
	  	left(left), right(right), bottom(bottom), top(top), 
		hres(_hres), vres(_vres)
{
	assert(left < 0 && left < right);
	assert(bottom < 0 && bottom < top);
}



#endif // _IMAGE_PLANE_H_
