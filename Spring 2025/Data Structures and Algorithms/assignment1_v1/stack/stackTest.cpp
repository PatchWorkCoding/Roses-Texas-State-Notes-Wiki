#include <iostream>
#include <cassert>
#include "MyStack.h"

void postfixTest() {
	MyStack operandStack(100);
	std::cout << "Please enter the operands (integers 1~9) and operators (+, -, *, /) one by one..." << std::endl;
	std::cout << "and enter '=' to indicate the end of the expression and to output the result." << std::endl;
	
	while(true) {
		char inputHolder;
		std::cin >> inputHolder;

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

