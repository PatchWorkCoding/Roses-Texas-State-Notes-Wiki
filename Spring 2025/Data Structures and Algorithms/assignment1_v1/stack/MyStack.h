#ifndef MYSTACK_H
#define MYSTACK_H

class MyStack {

	int maxSize;     // the max number of elements could be in this stack
	int *arr;        // the array holding the data
	int top;         // the index of the top element

public:

	/*
	 * Create a new stack object, which is initially empty.
	 *
	 * Input: maxSize is the maximum number of elements that can be stored in the stack.
	 */
	MyStack(int maxSize);

	/*
	 * Free all memory associated with the stack.
	 */
	~MyStack();

	/*
 	 * Add an element to the top of the stack.
 	 * Note that pushing an element on a full stack will throw a runtime_error exception.
	 *
	 * Input: e is the element that will be pushed on a stack
	 * Output: throw a runtime_error exception if the stack is full.
	 */
	void push(int e);

	/*
 	 * Remove an element from the top of the stack.
 	 * Note that popping on an empty stack will throw a runtime_error exception.
	 *
	 * Output: return the element e that is popped.
	 *         throw a runtime_error exception if the stack is empty.
	 */
	int pop();

	/*
	 * Check whether the stack is empty.
	 *
 	 * Output: return true if and only if the stack is empty.
 	 */
	bool empty() const;

	/*
 	 * Check whether the stack is full.
	 *
	 * Output: return true if and only if the stack is full.
	 */
	bool isFull() const;
};

#endif
