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
	assert(exp >= 0); //Ensures exponent is never less than 0

	//We check to see if the exponent is evenly divisible
	if (exp % 2 == 0)
	{
		//We then check to see if the exponent is 0, if so we return 1
		if (exp == 0) {
			return 1;
		}

		//Otherwise we calculate the value of base^(exp / 2) and return that value squared
		double value = improvedPowWithPosIntExp(base, exp / 2);
		return value * value;
	}

	else
	{
		//If the exponent is od we check to see if it is equal to 1, if so we return the base
		if (exp == 1) {
			return base;
		}

		//Otherwise we notice that base^exp is equivalent to base * base^(exp - 1)  and that (exp - 1) is an even number
		//We then repeat the steps we did for an even exponent this time making sure to multiple the result by base
		double value = improvedPowWithPosIntExp(base, (exp - 1) / 2);
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
	//If the base is 0 and the exponent is less than throw an error as the result is undefined
	if(base == 0 && exp < 0) {
		throw std::runtime_error("Error! Result is Undefined");
	}

	//If the exponent is negative return 1 over the base^exp
	else if (exp < 0)
	{
		//We multiple exp * -1 so the value is positive as per the requirements of the improvedPowWithPosIntExp()
		return 1.0 / improvedPowWithPosIntExp(base, exp * -1);
	}

	//Otherwise return base^exp
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
