#include "image.h"
#include "vector_ops.h"

int main(int argc, char** argv)
{
	vector<double> v1(2);
	vector<double> v2(2);

	v1(0) = 1;
	v1(1) = 1;
	
	v2(0) = 5;
	v2(1) = 3;

	int d = dot_product(v1, v2);
	
	std::cout << d << std::endl;
	//std::cout << v3(0) << " " << v3(1) << std::endl;

	return 0;
}
	
