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
double improvedPowWithPosIntExp(double base, int exp) {
	if (exp == 1) {
		return base;
	}
	if (exp % 2 == 0)
	{
		int value = improvedPowWithPosIntExp(base, exp / 2);
		return value * value;
	}
	else
	{
		int value = improvedPowWithPosIntExp(base, (exp - 1) / 2);
		return base * value * value;
	}
	
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
double improvedPow(double base, int exp) {
	if(base == 0 && exp < -1) {
		throw std::runtime_error("Error! Result is Undefined");
	}

	else if (exp == 0)
	{
		return 0;
	}

	else if (exp < 0)
	{
		return 1.0 / improvedPowWithPosIntExp(base, exp * -1);
	}

	return improvedPowWithPosIntExp(base, exp);
}


int main() {
	std::cout << "A faster method to calculate x^y ..." << std::endl;

	double x;
	int y;

	std::cout << "Please enter a floating-point number x: ";
	std::cin >> x;
	std::cout << "Please enter an integer y: ";
	std::cin >> y;

	std::cout << improvedPow(x,y) << std::endl;

	return 0;
}
