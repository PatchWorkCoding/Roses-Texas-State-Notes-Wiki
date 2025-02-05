#include <iostream>
#include "MyQueue.h"

int main() {
	std::cout << "Testing the template myQueue, try an integer queue as an example..." << std::endl;
	std::cout << "Please enter the max size of the int queue: ";
	int capacity;
	std::cin >> capacity;
	
	MyQueue<int> testIntQ(capacity);
	
	while(true) {
		std::cout << "Please enter 'e' for enqueue, 'd' for dequeue, and 's' for stop." << std::endl;
		char userOption;
		std::cin >> userOption;
		
		if (userOption == 's')
			break;
			
		switch(userOption) {
			case 'e':
				if(!testIntQ.isFull()) {
					std::cout << "Please enter the integer you want to enqueue: ";
					int val;
					std::cin >> val;
					testIntQ.enqueue(val);
				} else {
					std::cout << "Cannot enqueue. The queue is full." << std::endl;
				}
				break;
			case 'd':
				if(!testIntQ.empty())
					std::cout << testIntQ.dequeue() << " has been popped out." << std::endl;
				else
					std::cout << "Cannot pop. The queue is empty." << std::endl;
				break;
			default:
				std::cout << "Illegal input character for options." << std::endl;
		}
	}	
	
	return 0;
}
