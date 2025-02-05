#include <iostream>
#include <cassert>
#include "MyStack.h"

void postfixTest() {
	MyStack operandStack(100);
	std::cout << "Please enter the operands (integers 1~9) and operators (+, -, *, /) one by one..." << std::endl;
	std::cout << "and enter '=' to indicate the end of the expression and to output the result." << std::endl;

	// We keep track of the digits and operators so we can skip computation if digitCounter != operatorCounter -1.
	// Note that in a valid expression there will always be one more digit than operator

	int digitCounter = 0;	 // keeps track of the number of digits in the expression
	int operatorCounter = 0; // keeps track of the number of operators in the expression
	
	while (true) {
		char inputHolder;
		std::cin >> inputHolder;

		// If the input is an '=' we know the expression has ended and we can break out of the loop
		if (inputHolder == '=')
		{
			break;
		}

		// We first check to see if the inputted character is a digit
		int possibleDigit = static_cast<int>(inputHolder - '0'); //We cache the variable so we don't have to cast it multiple times
		
		//If it is a valid digit push it to the stack and increment the digit counter
		if (possibleDigit >= 0 && possibleDigit <= 9) {
			operandStack.push(possibleDigit);
			digitCounter++;
		}



		// TODO

		// Tips:
		//   1) You can convert a character into an integer by this expression: static_cast<int>(inputHolder-'0'),
	    //      where inputHolder stores the character which is either 0, 1, 2, 3, 4, 5, 6, 7, 8, or 9.
		//   2) You can catch an exception by try { ... } catch(const std::exception& e) { ... }. There is no
		//      need to distinguish different type of exceptions in this try-catch statement.
		//   3) Please print the error messages that are the same as the error messages in the test cases in the
		//      handout. In addition, you need to catch other errors that are not shown in the test cases in the
	    //      handout (e.g., the user enters unknown operators or characters.)
        //   4) You can exit the infinite while-loop by using either a break statement or a return statement.
	}
}

int main() {
    std::cout << "Testing the basic functions of the stack..." << std::endl;
	std::cout << "Please enter the max capacity of the testStack: ";

	int testSize;
	std::cin >> testSize;
	MyStack testStack(testSize);
	
	std::cout << "Testing..." << std::endl;
	while(true) {
		std::cout << "Please enter 'p' for push, 'o' for pop, 'e' for exit:  ";
		char userChoice;
		std::cin >> userChoice;
		
		if (userChoice == 'e')
			break;
		
		switch (userChoice) {
			case 'p':
				if(!testStack.isFull()) {
					std::cout << "Please enter the integer you would like to push: ";
					int userInt;
					std::cin >> userInt;
					testStack.push(userInt);
				} else {
					std::cout << "Nothing has been pushed in. The stack is full!" << std::endl;
				}
				break;
			case 'o':
				if(!testStack.empty())
					std::cout << testStack.pop() << " has been popped out" << std::endl;
				else
					std::cout << "Nothing has been popped out. The stack is empty!" << std::endl;
				break;
			default:
				std::cout << "Illegal user-input character. Please try again." << std::endl;
		}
	}

	std::cout << "Now, start to use a stack to evaluate postfix expressions..." << std::endl;
	postfixTest();	
	
	return 0;
}

