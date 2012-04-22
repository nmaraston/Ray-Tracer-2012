#include "image.h"

int main(int argc, char** argv)
{
	image<byte> myImage(200, 200, 3);

	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++) {
			myImage(i,j,0) = 255;
			myImage(i,j,1) = 0;
			myImage(i,j,2) = 0;
		}
	}
	
	myImage.save_ppm("image.ppm");

	return 0;
}
	
