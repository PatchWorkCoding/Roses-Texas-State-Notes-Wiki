#include <iostream>
#include <cstring>
#include <cassert>

#include "heapsort.h"


void printMenu() {
    std::cout << "Please select one of the following options:" << std::endl;
    std::cout << std::endl;
    std::cout << "(a) Enter a sequence of nonnegative integers (-1 signals the end of the sequence)." << std::endl;
    std::cout << "(b) Use heapsort to sort the entire array." << std::endl;
    std::cout << std::endl;
    std::cout << "(c) Build a max-heap from the sequence you entered." << std::endl;
    std::cout << "(d) Swap the root node with the last node in the heap." << std::endl;
    std::cout << "(e) Reduce the heap size by one." << std::endl;
    std::cout << "(f) Run max-heapify(i) at the node i in the heap." << std::endl;
    std::cout << std::endl;
    std::cout << "(g) Get the index of the left child of the node i." << std::endl;
    std::cout << "(h) Get the index of the right child of the node i." << std::endl;
    std::cout << "(i) Get the index of the parent of the node i." << std::endl;
    std::cout << std::endl;
    std::cout << "(j) Check whether the node i is a valid node id." << std::endl;
    std::cout << "(k) Check whether the node i is a leaf node." << std::endl;
    std::cout << "(l) Check whether the node i is an internal node." << std::endl;
    std::cout << std::endl;
    std::cout << "(m) Print the array." << std::endl;
    std::cout << "(n) Print the unsorted part of the array." << std::endl;
    std::cout << "(o) Print the sorted part of the array." << std::endl;
    std::cout << std::endl;
    std::cout << "(p) Print the preorder traversal of the heap." << std::endl;
    std::cout << "(q) Print the postorder traversal of the heap." << std::endl;
    std::cout << "(r) Print the inorder traversal of the heap." << std::endl;
    std::cout << std::endl;
    std::cout << "(s) Draw the heap graphically." << std::endl;
    std::cout << std::endl;
    std::cout << "(y) Print this menu again." << std::endl;
    std::cout << "(z) Quit this program." << std::endl;
}

int main(int argc, char *argv[]) {

    // the -q option turns off some outputs to help grading
    bool isVerbose = true;

    if (argc == 2) {
        if (strcmp(argv[1], "-q") == 0) {
            isVerbose = false;
        }
    }

    try {

        if (isVerbose) {
            printMenu();
            std::cout << std::endl;
        }
        HeapSort<int>* heapSort = nullptr;

        bool isExit = false;

        while (!isExit) { // loop until the user choose to quit

            if (isVerbose)
                std::cout << "Please enter your option: ";
            char choice;
            std::cin >> choice;

            std::cin.get(); // get rid of the newline character

            switch (choice) {
            case 'a':  // Enter a sequence of nonnegative integers (-1 signals the end of the sequence).
            {
                if (heapSort != nullptr) {
                    delete heapSort;
                    heapSort = nullptr;
                }

                if (isVerbose)
                    std::cout << "Please enter a sequence of nonnegative integers (-1 signals the end of the sequence): " << std::endl;
 
                int numbers[MAX_HEAPSORT_SIZE];
                int n = 0;

                while(true) {
                    std::cin >> numbers[n];
                    if (numbers[n] == -1) break;
                    n++;
                }
                heapSort = new HeapSort<int>(numbers, n);
                break;
            }
            case 'b': // Use heapsort to sort the entire array.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                heapSort->heapSort();
                if (isVerbose)
                    std::cout << "The array has been sorted." << std::endl;
                break;
            }
            case 'c': // Build a max-heap from the sequence you entered.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                heapSort->buildMaxHeap();
                if (isVerbose)
                    std::cout << "The max-heap has been built." << std::endl;
                break;
            }
            case 'd': // Swap the root node with the last node in the heap.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                if (heapSort->getHeapSize() == 0) {
                    if (isVerbose)
                        std::cout << "The heap is empty." << std::endl;
                    break;
                }
                heapSort->swapNode(1, heapSort->getHeapSize());
                if (isVerbose)
                    std::cout << "The root node and the last node have been swapped." << std::endl;
                break;
            }
            case 'e': // Reduce the heap size by one.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                if (heapSort->getHeapSize() == 0) {
                    if (isVerbose)
                        std::cout << "The heap is empty." << std::endl;
                    break;
                }
                heapSort->reduceHeapSizeByOne();
                if (isVerbose)
                    std::cout << "The heap size has been reduced by one." << std::endl;
                break;
            }
            case 'f': // Run max-heapify(i) at the node i in the heap. 
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }

                if (isVerbose)
                    std::cout << "Please enter the node id: ";
                int i;
                std::cin >> i;
                if (!heapSort->isValidNodeId(i)) {
                    if (isVerbose)
                        std::cout << "Invalid node id." << std::endl;
                    break;
                }
                heapSort->maxHeapify(i);
                if (isVerbose)
                    std::cout << "maxHeapify(" << i << ") has been run." << std::endl;
                break;
            }
            case 'g': // Get the index of the left child of the node i.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                
                if (isVerbose)
                    std::cout << "Please enter the node id: ";
                int i;
                std::cin >> i;
                if (!heapSort->isValidNodeId(i)) {
                    if (isVerbose)
                        std::cout << "Invalid node id." << std::endl;
                    break;
                }
                if (isVerbose)
                    std::cout << "The index of the left child of node " << i << " is ";
                std::cout << heapSort->getLeftChildIndex(i);
                if (isVerbose)
                    std::cout << ".";
                std::cout << std::endl;
                break;
            }
            case 'h': // Get the index of the right child of the node i.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                
                if (isVerbose)
                    std::cout << "Please enter the node id: ";
                int i;
                std::cin >> i;
                if (!heapSort->isValidNodeId(i)) {
                    if (isVerbose)
                        std::cout << "Invalid node id." << std::endl;
                    break;
                }

                if (isVerbose)
                    std::cout << "The index of the right child of node " << i << " is ";
                std::cout << heapSort->getRightChildIndex(i);
                if (isVerbose)
                    std::cout << ".";
                std::cout << std::endl;
                break;
            }
            case 'i': // Get the index of the parent of the node i.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                
                if (isVerbose)
                    std::cout << "Please enter the node id: ";
                int i;
                std::cin >> i;
                if (!heapSort->isValidNodeId(i)) {
                    if (isVerbose)
                        std::cout << "Invalid node id." << std::endl;
                    break;
                }

                if (isVerbose)
                    std::cout << "The index of the parent of node " << i << " is ";
                std::cout << heapSort->getParentIndex(i);
                if (isVerbose)
                    std::cout << ".";
                std::cout << std::endl;
                break;
            }
            case 'j': // Check whether the node i is a valid node id.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                
                if (isVerbose)
                    std::cout << "Please enter the node id: ";
                int i;
                std::cin >> i;

                if (isVerbose)
                    std::cout << "Node " << i << " is ";
                if (heapSort->isValidNodeId(i)) {
                    std::cout << "valid" ;
                } else {
                    std::cout << "invalid";
                }
                if (isVerbose)
                    std::cout << ".";
                std::cout << std::endl;
                break;
            }
            case 'k': // Check whether the node i is a leaf node.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                
                if (isVerbose)
                    std::cout << "Please enter the node id: ";
                int i;
                std::cin >> i;
                if (!heapSort->isValidNodeId(i)) {
                    if (isVerbose)
                        std::cout << "Invalid node id." << std::endl;
                    break;
                }

                if (heapSort->isLeaf(i)) {
                    std::cout << "Yes" ;
                    if (isVerbose)
                        std::cout << ", node " << i << " is a leaf node.";
                } else {
                    std::cout << "No";
                    if (isVerbose)
                        std::cout << ", node " << i << " is not a leaf node.";
                }
                std::cout << std::endl;
                break;
            }
           case 'l': // Check whether the node i is an internal node.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                
                if (isVerbose)
                    std::cout << "Please enter the node id: ";
                int i;
                std::cin >> i;
                if (!heapSort->isValidNodeId(i)) {
                    if (isVerbose)
                        std::cout << "Invalid node id." << std::endl;
                    break;
                }

                if (heapSort->isInternalNode(i)) {
                    std::cout << "Yes" ;
                    if (isVerbose)
                        std::cout << ", node " << i << " is an internal node.";
                } else {
                    std::cout << "No";
                    if (isVerbose)
                        std::cout << ", node " << i << " is not an internal node.";
                }
                std::cout << std::endl;
                break;
            }
            case 'm': // Print the array.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                if (isVerbose)
                    std::cout << "The array is: ";
                heapSort->printArray();
                std::cout << std::endl;
                break;
            }
            case 'n': // Print the unsorted part of the array.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                if (isVerbose)
                    std::cout << "The unsorted part of the array is: ";
                heapSort->printUnsortedPartOfArray();
                std::cout << std::endl;
                break;
            }
            case 'o': // Print the sorted part of the array.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                if (isVerbose)
                    std::cout << "The sorted part of the array is: ";
                heapSort->printSortedPartOfArray();
                std::cout << std::endl;
                break;
            }
            case 'p': // Print the preorder traversal of the heap.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                if (isVerbose)
                    std::cout << "The preorder traversal is: ";
                heapSort->printPreorderTraversal();
                std::cout << std::endl;
                break;
            }
            case 'q': // Print the postorder traversal of the heap.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                if (isVerbose)
                    std::cout << "The postorder traversal is: ";
                heapSort->printPostorderTraversal();
                std::cout << std::endl;
                break;
            }
            case 'r': // Print the inorder traversal of the heap.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                if (isVerbose)
                    std::cout << "The inorder traversal is: ";
                heapSort->printInorderTraversal();
                std::cout << std::endl;
                break;
            }
            case 's': // Draw the heap graphically.
            {
                if (heapSort == nullptr) {
                    if (isVerbose)
                        std::cout << "No sequence entered." << std::endl;
                    break;
                }
                if (isVerbose)
                    std::cout << "The drawing of the heap is: " << std::endl;
                heapSort->drawHeapGraphically();
                break;
            }
            case 'y': // print this menu again
                if (isVerbose) {
                    std::cout << std::endl;
                    printMenu();
                }
                break;
            case 'z': // exit the program
                if (isVerbose)
                    std::cout << "Bye!" << std::endl;
                isExit = true;
                break;
            default:
                std::cout << "Error: Unknown option." << std::endl;
            }

            if (isVerbose)
                std::cout << std::endl;
        }

        if (heapSort != nullptr) {
            delete heapSort;
            heapSort = nullptr;
        }
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
