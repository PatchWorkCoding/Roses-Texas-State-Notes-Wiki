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
	assert(exp >= 0); //Ensures exponent is never less than 0
	
	//If the exponent is 0 then return 1
	if (exp == 0) {
		return 1;

	}
	
	//Otherwise call the function again and return its output * base
	return base * powWithPosIntExp(base, exp - 1);
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
	
	//If the base is 0 and the exponent is less than throw an error as the result is undefined
	if(base == 0 && exp < 0) {
		throw std::runtime_error("Error! Result is Undefined");
	}

	//If the exponent is negative return 1 over the base^exp
	else if (exp < 0) {
		//We multiple exp * -1 so the value is positive as per the requirements of the powWithPosInt()
		return 1.0 / powWithPosIntExp(base, exp * -1);
	}

	//Otherwise return base^exp
	return powWithPosIntExp(base, exp);
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

