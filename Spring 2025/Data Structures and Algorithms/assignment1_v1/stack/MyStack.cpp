#include <iostream>
#include <cassert>
#include "MyStack.h"


/*
 * Create a new stack object, which is initially empty.
 *
 * Input: maxSize is the maximum number of elements that can be stored in the stack.
 */
MyStack::MyStack(int maxSize) : maxSize(maxSize) {
	// TODO
}


/*
 * Free all memory associated with the stack.
 */
MyStack::~MyStack() {
	// TODO
}

/*
 * Add an element to the top of the stack.
 * Note that pushing an element on a full stack will throw a runtime_error exception.
 *
 * Input: e is the element that will be pushed on a stack
 * Output: throw a runtime_error exception if the stack is full.
 */
void MyStack::push(int e) {
	// TODO
}


/*
 * Remove an element from the top of the stack.
 * Note that popping on an empty stack will throw a runtime_error exception.
 *
 * Output: return the element e that is popped.
 *         throw a runtime_error exception if the stack is empty.
 */
int MyStack::pop() {
	// TODO
}


/*
 * Check whether the stack is empty.
 *
 * Output: return true if and only if the stack is empty.
 */
bool MyStack::empty() const {
	// TODO
}


/*
 * Check whether the stack is full.
 *
 * Output: return true if and only if the stack is full.
 */
bool MyStack::isFull() const {
	// TODO
}

