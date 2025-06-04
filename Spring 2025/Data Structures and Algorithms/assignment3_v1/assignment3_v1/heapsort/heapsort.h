#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include <cassert>

// TODO: You may want to include a few more header files here.

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
        return i > (heap_size / 2); 
    }

    bool isInternalNode(int i) const {
        return i <= (heap_size / 2);
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
    for(int i = 0; i < size; i++) {
        arr[i + 1] = numbers[i];
    }
}

template<typename T>
void HeapSort<T>::buildMaxHeap() {
    heap_size = size;
    for(int i = heap_size / 2; i >= 1; i--) {
        maxHeapify(i);
    }
}

template<typename T>
void HeapSort<T>::maxHeapify(int i) {
    int leftIndex = getLeftChildIndex(i);
    int rightIndex = getRightChildIndex(i);
    
    if(isValidNodeId(rightIndex) && arr[rightIndex] > arr[i]) {
        swapNode(i, rightIndex);
        maxHeapify(rightIndex);
    }

    else if(isValidNodeId(leftIndex) && arr[leftIndex] > arr[i]) {
        swapNode(i, leftIndex);
        maxHeapify(leftIndex);
    }
}

template<typename T>
void HeapSort<T>::heapSort() {
    buildMaxHeap();

    for(int i = heap_size; i >= 2; i--) {
        swapNode(1, i);
        //reduceHeapSizeByOne();
        maxHeapify(i);
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
    std::cout << arr[i] << " ";
    int leftIndex = getLeftChildIndex(i);
    if(isValidNodeId(leftIndex))
        printPreorderTraversal(leftIndex);
    
    int rightIndex = getRightChildIndex(i);
    if(isValidNodeId(rightIndex))
            printPreorderTraversal(rightIndex);
}

template<typename T>
void HeapSort<T>::printPostorderTraversal(int i) {   
    int leftIndex = getLeftChildIndex(i);
    if(isValidNodeId(leftIndex))
        printPreorderTraversal(leftIndex);
    
    int rightIndex = getRightChildIndex(i);
    if(isValidNodeId(rightIndex))
            printPreorderTraversal(rightIndex);

    std::cout << arr[i] << " ";
}

template<typename T>
void HeapSort<T>::printInorderTraversal(int i) {
    int leftIndex = getLeftChildIndex(i);
    if(isValidNodeId(leftIndex))
        printPreorderTraversal(leftIndex);
    
    std::cout << arr[i] << " ";

    int rightIndex = getRightChildIndex(i);
    if(isValidNodeId(rightIndex))
            printPreorderTraversal(rightIndex);
}

template<typename T>
void HeapSort<T>::drawHeapGraphically() {
    
    // TODO: The implementation of this function is optional since this is a bonus task.
}

#endif // HEAPSORT_H
