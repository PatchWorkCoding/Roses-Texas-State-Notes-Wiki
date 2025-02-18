#include <iostream>
#include <cassert>

/*
 * Compute the exponentiation base^exp, where exp is a positive integer and base is non-zero.
 *
 *   base - the base, which is a non-zero floating-point number (i.e., base != 0.0)
 *   exp  - the exponent, which is a postive integer (i.e., exp > 0)
 *
 * Output:
 *   Return base^exp.
 */
double powWithPosIntExp(double base, int exp) {
	// TODO
}


/*
 * Compute the exponentiation base^exp.
 *
 *   base - the base, which is a floating-point number
 *   exp  - the exponent, which is an integer
 *
 * Output:
 *   Return base^exp. If base is 0.0 and exp is negative, throw an exception
 */
double pow(double base, int exp) {
	// TODO
}


int main() {
	std::cout << "Calculate x^y ..." << std::endl;
	
	double x;
	int y;

	std::cout << "Please enter a floating-point number x: ";
	std::cin >> x;
	std::cout << "Please enter an integer y: ";
	std::cin >> y;
	
	std::cout << pow(x,y) << std::endl;

	return 0;
}

