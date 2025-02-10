#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <cassert>

template <class T>
class MyQueue {

	T *arr;           // the array holding the data
	int front_idx;    // index of the "reserved" slot before the front element
    int rear_idx;     // index of the rear element
	int arraySize;    // The size of the array.
	                  // Keep in mind that the Queue can only hold maxSize elements,
				      // where maxSize = (arraySize - 1)

public:

	/*
	 * Create a new queue object, which is initially empty.
	 *
	 * Input: maxSize is the maximum number of elements that can be stored in the queue.
	 */
	MyQueue(int maxSize);

	/*
	 * Free all memory associated with the queue.
	 */
	~MyQueue();

	/*
	 * Add an element to the queue.
	 *
	 * Input: e is the element that will be enqueued.
	 */
	void enqueue(T e);

	/*
	 * Remove the first element in the queue.
	 *
	 * Output: e is the first element that is dequeued.
	 */
	T dequeue();

	/*
	 * Return the first element in the queue but does not remove it.
	 *
	 * Output: e is the first element that is peeked.
	 */
	T peek();

	/*
	 * Return the number of elements in the queue.
	 *
	 * Output: return the number of elements in the queue.
	 */
	int size() const;

	/*
	 * Check whether the queue is empty.
	 *
	 * Output: return true if and only if the queue is empty.
     */
	bool empty() const;

	/*
	 * Check whether the queue is full.
	 *
	 * Output: return true if and only if the queue is full.
	 */
	bool isFull() const;
};


/*
 * Create a new queue object, which is initially empty.
 *
 * Input: maxSize is the maximum number of elements that can be stored in the queue.
 */
template <class T>
MyQueue<T>::MyQueue(int maxSize) : arraySize(maxSize+1) {
	arr = new T[arraySize];
	front_idx = 0;
	rear_idx = 0;
}


/*
 * Free all memory associated with the queue.
 */
template <class T>
MyQueue<T>::~MyQueue() {
	delete [] arr;
}


/*
 * Add an element to the queue.
 *
 * Input: e is the element that will be enqueued.
 */
template <class T>
void MyQueue<T>::enqueue(T e) {
	//Throws an Error if the queue is full
	if (isFull())
	{
		throw std::runtime_error("Error! Queue Overflow");
	}
	
	//Otherwise adds an element to the queue and increments the rear index
	arr[rear_idx] = e;
	rear_idx = (rear_idx + 1) % arraySize;
}


/*
 * Remove the first element in the queue.
 *
 * Output: e is the first element that is dequeued.
 */
template <class T>
T MyQueue<T>::dequeue() {
	//Throws an Error if the queue is empty
	if (empty())
	{
		throw std::runtime_error("Error! Queue Underflow");
	}

	//Otherwise we return the result and increment the front index 
	T e = arr[front_idx];
	front_idx = (front_idx + 1) % arraySize;
	return e;
}


/*
 * Return the first element in the queue but does not remove it.
 *
 * Output: e is the first element that is peeked.
 */
template <class T>
T MyQueue<T>::peek() {
	//Returns the next element in the queue
	return arr[front_idx];
}


/*
 * Return the number of elements in the queue.
 *
 * Output: return the number of elements in the queue.
 */
template <class T>
int MyQueue<T>::size() const {
	//Calculates the size of queue based on on the position of the front and rear indexes 
	return (rear_idx - front_idx + arraySize) % arraySize;
}


/*
 * Check whether the queue is empty.
 *
 * Output: return true if and only if the queue is empty.
 */
template <class T>
bool MyQueue<T>::empty() const {
	return rear_idx == front_idx;
}


/*
 * Check whether the queue is full.
 *
 * Output: return true if and only if the queue is full.
 */
template <class T>
bool MyQueue<T>::isFull() const {
	return (rear_idx + 1) % (arraySize) == front_idx;
}


#endif