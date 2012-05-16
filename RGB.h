#ifndef _RGB_H_
#define _RGB_H_


class RGB {

	public:
		
		inline RGB(char r, char g, char b);
	
		char r;
		char g;
		char b;

		
		// Some helper colours:
		static const RGB RED;
		static const RGB GREEN;
		static const RGB BLUE;
		static const RGB GREY;

};


// Inline implementations:


inline
RGB::RGB(char r, char g, char b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}


#endif // _RGB_H_

