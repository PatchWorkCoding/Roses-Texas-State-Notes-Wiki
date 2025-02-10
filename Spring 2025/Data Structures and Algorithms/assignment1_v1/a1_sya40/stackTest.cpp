#include <iostream>
#include <cassert>
#include "MyStack.h"

void postfixTest() {
	MyStack operandStack(100);
	std::cout << "Please enter the operands (integers 1~9) and operators (+, -, *, /) one by one..." << std::endl;
	std::cout << "and enter '=' to indicate the end of the expression and to output the result." << std::endl;
	
	while (true) {
		char inputHolder;
		std::cin >> inputHolder;

		// If the input is an '=' we know the expression has ended and we can break out of the loop
		if (inputHolder == '=')
		{
			int result = operandStack.pop();

			//We check to make sure that their was only one number left
			if (operandStack.empty())
			{
				//Output the result if true
				std::cout << "The entered post-fix expression results in " << result << std::endl;
			}  
			else {
				//Output an error if false
				std::cout << "The entered post-fix expression was not a legal one." << std::endl;
			}
			return;
		}

		// We get the user inputted digit
		int inputDigit = static_cast<int>(inputHolder - '0'); //We cache the variable so we don't have to cast it multiple times
		
		//If it is a valid digit push it to the stack
		if (inputDigit >= 0 && inputDigit <= 9) {
			operandStack.push(inputDigit);
		}

		//Else we check to see if it is an operator
		else if (inputHolder == '+' || inputHolder == '-' || inputHolder == '*'|| inputHolder == '/') {
			
			int rhs; //Right Hand Side of the expression
			int lhs; //Left Hand Side of the expression

			//Attempts to pop the rhs from the stack if the stack is not empty, and returns an error if it is unsuccessful
			if (!operandStack.empty())
			{
				rhs = operandStack.pop();
			}
			else {
				std::cout << "Error! No sufficient operands." << std::endl;
				return;
			}

			//Attempts to do the same as the rhs for the lhs
			if (!operandStack.empty())
			{
				lhs = operandStack.pop();
			}
			else {
				std::cout << "Error! No sufficient operands." << std::endl;
				return;
			}
			

			//Applies the correct operate based on user input and pushes the result to the stack
			if (inputHolder == '+') {
					operandStack.push(lhs + rhs);
			}
			else if (inputHolder == '-') {
				operandStack.push(lhs - rhs);
			}
			else if (inputHolder == '*') {
				operandStack.push(lhs * rhs);
			}
			else if (inputHolder == '/') {
				//Outputs an error if the user attempts to divide by zero
				if (rhs == 0) {
						std::cout << "Error! Attempted division by zero." << std::endl;
						return;
				}
					
				operandStack.push(lhs / rhs);
			}

			
		}
		
		//If the user did not provide a valid input we alert the them and then continue operation
		else {
			std::cout << "Not a valid input, Please enter the operands (integers 1~9) or operators (+, -, *, /)" << std::endl;
		}
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

