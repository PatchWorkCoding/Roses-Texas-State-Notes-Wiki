The 3 problems with array:
* Need to know the size of the array before you define you define it
* Array must be contagious in memory space which you might not have
* Insertion, deletion, and resizing your array are all costly operations

Linked List Problems:
* Randomly Accessing data is very costly
* Needs more memory per node than an array
* Not very friendly to the Cache System because it breaks the principle of locality.

Quick Cache Review: Cache works based on the principle of locality. The data cache it assumes the all the relevant data is stored next to each other like in an array or stack.

**Container Class**: A class used to store/retrieve data

**Elements**: The data stored in a container class

**Singly Linked List**: Each node only points to the proceeding node

**Doubly Linked List**: Each Node is linked to the nodes preceding and proceeding it

**Circularly Linked List**: like a singly linked list but the last node is pointing to first node. A->B->C->A

Don't delete a node until you have already swapped the pointers so you don't loose references

ADT are like specification documents for a data type that are data type agnostic 