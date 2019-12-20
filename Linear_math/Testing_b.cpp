#include <iostream>
#include <array>
#include <assert.h>
#include "linear_math.h"

using namespace linear_math;

int main() {

	Vector<int, 3> k{ 1,2,3 };
	Vector<int, 3> l{ 3,2,1 };
	k = k + l;
	std::cout << k;
	
	return EXIT_SUCCESS;
}