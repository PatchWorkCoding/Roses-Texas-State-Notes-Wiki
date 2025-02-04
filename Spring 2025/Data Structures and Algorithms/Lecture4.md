# Lecture 4: Stacks and Queues;

## Stack:
A LiFo queue. Last in First out

Stacks basic operations:
* Push - adds an item to the stack
* Pop - removes an item from the stack. (In C++ the value of the item is **not** returned)
* Peek - returns the value at the top of the stack
* Size - returns how large the size is
* Empty - returns true if the stack is empty and false otherwise

typedef is an obsolete feature

int foo() const; <- means that the function cannot modify any data. All functions are pointers to parts of memory in C++ *at lest I think that is the case.*

Look into the *Move construct* / *Move semantic*

**Stack Underflow**: Happens when you try to pop an empty stack

**Stack Overflow**: Happens when you try to push to a full stack

2 + (5 * 1) = 2 5 1 * +
(2 + 5) * 1 = 2 5 + 1 *

post fix is a way of representing the was a stack does math

2 5 1 * +: put 2 in the buffer, put 5 in the buffer, put 1 in the buffer, multiply 1 and 5 put the result in the stack, add the result and 2 to put the result in the stack

When you see the "=" you need to make sure you only have 1 item left

***

## Queue

FiFo (First in First out structure)

Queues are very useful for sequencings. If you have a lot of requests received during a cycle you need to store them somewhere to be processed in the correct order

**ADT Queues:**
* Enqueue - add an element to the queue
* Dequeue - remove an element from the queue
* Peek - looks at the front element
* Size - returns how long the queue is
* Empty - returns true if the queue is empty and false otherwise

For a queue you always need two indexes one for the front and one for the back. Because you need to load new elements into the back and take elements from the front

Like a stack it can be implemented as either an array or a linked list

**Linked List**: you need a head pointer and a tail pointer. The head is the front and the tail is the back. 
* When you enqueue you insert it at the tail
* When you dequeue you remove it at the head

*Make sure to update the head pointer first!*

**Array:** you have two integers, the front index and the back index.
* When you enqueue you add a number to the array at the back index, and then increment the front index by 1 and cycle it back around
```
void Enqueue(int v) {
    if(!isFull()) {
        queueArr[back] = v;
        back = (back + 1) % maxSize;
    }
    else {
        cout << "ERROR!!";
    }
} 
```
* When you Dequeue you return the number at the front index, and then you increase the front index by one. *You might need to remove the value from the array if the data type is complex*

```
int Dequeue() {
    if(!isFull()) {
        int dequeueValue = queueArr[front];
        front = (front + 1) % maxSize;

        return dequeueValue;
    }
    else {
        cout << "ERROR!!";
    }
} 
```
* When you want to check the size of the queue you can either: 
    * Keep track of the size in a separate variable. incrementing it on enqueue and decrementing it on dequeue.
    * You just use `(((front - rear) + 1) + maxSize) % maxSize` but this can't distinguish between whether the queue is full or empty.

in order to fix the `(((front - rear) + 1) + maxSize) % maxSize` problem you need to "reserve" an index for the front, where the front is always taking up an unused space. You can now tell the queue is full because `(back + 1) % maxSize == front` and the queue is empty because `front == back`

**Queue Overflow**: Enqueue to a full queue
**Queue Underflow**: dequeuing from an empty


***

## Assignment Notes:

You should use `#Include <cassert>` in your assignment for error handling! 

Make sure to handle "division by zero" error. The hand out will have all the specified error messages

