#include <iostream>
#include <array>
#include <assert.h>
#include "Vector.h"



int main() {

	Vector<int, 3> k{ 1,2,3 };
	Vector<int, 3> l{ 3,2,1 };
	k += l;
	std::cout << k;

	
	
	return EXIT_SUCCESS;
}