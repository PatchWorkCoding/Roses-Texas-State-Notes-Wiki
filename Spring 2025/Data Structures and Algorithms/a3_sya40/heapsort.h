#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include <cassert>


#define MAX_HEAPSORT_SIZE 1000


template<typename T>
class HeapSort {

    T arr[MAX_HEAPSORT_SIZE+1];
    int size;
    int heap_size;

public:

    HeapSort(T* numbers, int size);

    int getSize() const {
        return size;
    }

    int getHeapSize() const {
        return heap_size;
    }

    bool isValidNodeId(int i) const {
        return i >= 1 && i <= heap_size;
    }

    int getLeftChildIndex(int i) const {
        return i * 2;
    }

    int getRightChildIndex(int i) const {
        return (i * 2) + 1;
    }

    int getParentIndex(int i) const {
        return i / 2;
    }

    bool isLeaf(int i) const {
        assert(i != 0); //makes sure there is no divide by zero error

        return i > size / 2;
    }

    bool isInternalNode(int i) const {
        assert(i != 0); //makes sure there is no divide by zero error

        return i <= size / 2;
    }

    void buildMaxHeap();

    void swapNode(int i, int j) {
        std::swap(arr[i], arr[j]);
    }

    void reduceHeapSizeByOne() {
        heap_size--;
    }

    void maxHeapify(int i);

    void heapSort();

    void printArray();

    void printUnsortedPartOfArray();

    void printSortedPartOfArray();

    void printPreorderTraversal(int i=1);

    void printPostorderTraversal(int i=1);

    void printInorderTraversal(int i=1);

    void drawHeapGraphically();
};

template<typename T>
HeapSort<T>::HeapSort(T* numbers, int size) : size{size}, heap_size{size} {
    //Assigns all the values in numbers to arr with an offset of 1 so that
    // heap indexing can be performed easier.
    for(int i = 0; i < size; i++)
    {
        arr[i + 1] = numbers[i];
    }
}

template<typename T>
void HeapSort<T>::buildMaxHeap() {
    //Resets the max heap size in order to rebuild the whole heap
    heap_size = size;

    //performs maxHeapify on all the internal nodes
    for(int i = heap_size / 2; i > 0; i--) {
        maxHeapify(i);
    }
}

template<typename T>
void HeapSort<T>::maxHeapify(int i) {
    int largestIndex = i;
    int leftChildIndex = getLeftChildIndex(i);
    int rightChildIndex = getRightChildIndex(i);

    //if leftChildIndex is valid and its element is larger than the element at the
    // current largest index set the largest index equal to the leftChildIndex
    if(isValidNodeId(leftChildIndex) && arr[largestIndex] < arr[leftChildIndex])
	    largestIndex = leftChildIndex;

    //if rightChildIndex is valid and its element is larger than the element at the
    // current largest index set the largest index equal to the rightChildIndex
    if(isValidNodeId(rightChildIndex) && arr[largestIndex] < arr[rightChildIndex])
	    largestIndex = rightChildIndex;

    //if the current index is not the index of the largest element swap the elements 
    // and call maxHeapifiy one level down
    if(i != largestIndex) {
	    swapNode(i, largestIndex);
	    maxHeapify(largestIndex);
    }
}

template<typename T>
void HeapSort<T>::heapSort() {
    //Rebuild the heap so we start from a fresh postion
    buildMaxHeap();
   
    //sorts the heap into ascending order
    while(heap_size > 0) {
    	swapNode(1, heap_size);
	    heap_size--;
	    maxHeapify(1);
    }
}

template<typename T>
void HeapSort<T>::printArray() {
    for(int i = 1; i <= size; i++) {
        std::cout << arr[i] << " ";
    }
}

template<typename T>
void HeapSort<T>::printUnsortedPartOfArray() {
    for(int i = 1; i <= heap_size; i++) {
        std::cout << arr[i] << " ";
    }
}

template<typename T>
void HeapSort<T>::printSortedPartOfArray() {
    for(int i = heap_size+1; i <= size; i++) {
        std::cout << arr[i] << " ";
    }
}

template<typename T>
void HeapSort<T>::printPreorderTraversal(int i) {
    //print out the current element
    std::cout << arr[i] <<  " ";
    
    //traverse the left sub tree if it exists
    if(isValidNodeId(getLeftChildIndex(i)))
    	printPreorderTraversal(getLeftChildIndex(i));

    //traverse the right sub tree if it exists
    if(isValidNodeId(getRightChildIndex(i)))
    	printPreorderTraversal(getRightChildIndex(i));
}

template<typename T>
void HeapSort<T>::printPostorderTraversal(int i) {
    //traverse the left sub tree if it exists
    if(isValidNodeId(getLeftChildIndex(i)))
    	printPostorderTraversal(getLeftChildIndex(i));

    //traverse the right sub tree if it exists
    if(isValidNodeId(getRightChildIndex(i)))
    	printPostorderTraversal(getRightChildIndex(i));

    //print out the current element
    std::cout << arr[i] << " ";
}

template<typename T>
void HeapSort<T>::printInorderTraversal(int i) {
    //traverse the left sub tree if it exists
    if(isValidNodeId(getLeftChildIndex(i)))
   	    printInorderTraversal(getLeftChildIndex(i));
    
    //print out the current element
    std::cout << arr[i] << " ";

    //traverse the right sub tree if it exists
    if(isValidNodeId(getRightChildIndex(i)))
    	printInorderTraversal(getRightChildIndex(i));
}

template<typename T>
void HeapSort<T>::drawHeapGraphically() {
    // TODO: The implementation of this function is optional since this is a bonus task.
}

#endif // HEAPSORT_H
