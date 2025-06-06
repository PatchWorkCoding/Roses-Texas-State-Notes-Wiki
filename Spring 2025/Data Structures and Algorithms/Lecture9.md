# Heaps

## Tree:
A graph with no cycles in it.

**Root Node** - the beginning of a tree

I**internal nodes** - any node connecting the root node to the leaf nodes

**Leaf nodes** are the nodes with no children nodes

**Binary Tree**: a tree where each node has at most two elements
*   Binary Tree's have left children and right children

Nodes don't need to store the same data and in fact can be useful to store separate data in the leaf nodes than in the internal nodes such as representing the order of operations or compiler steps

In this class will only be studying binary tree

Another type of tree to look at would be [B-Tree](https://en.wikipedia.org/wiki/B-tree)

Directed Acyclic Graph (DAG) - Like a tree but with nodes that have multiple parents (Not a tree)

**Path** the number of **edges** connecting to nodes

**Height** the longest path in a tree, The largest chain from the root to the furthest leaf node

Paths are counted by edges not nodes

**Depth/Level** the length of path from the root to a given node

**Height of a Node** the length of the path from the given node to the furthest leaf 

*basically dept/level is defined from the root to the current node, whereas height is calculated from the leaf to the current node. they aren't inverses of each other because a leaf node has no height but could have varying depth.* 

### Important Concepts!
**Full binary Tree** a binary tree where each node has *exactly* two children or no children.

**Complete Binary Tree** a binary tree where each level is full except for the leaf level. and the leaf level is "left adjusted" meaning all the longest path of nodes is on the right side of the tree. The max number of nodes on a given level is = 2^level

**Perfect Binary Tree** A tree that is both a "Full Binary Tree" and a  "Complete Binary Tree"

"Completeness" is necessary feature for storing a tree structure in an array. which is the most efficient way of storing a tree.

**Equation Definitions of a Binary Tree:**
* At the level `l` there are at most `2^l` nodes in a binary tree
* A binary tree with height `d` has at most `(2^d+1) - 1` Nodes
* A binary tree with `n` Nodes has a height at least `floor(log^2(n))`
* `Height = floor(log^2(n))`
* `Nodes =  (2^height+1) - 1`

*Interesting little aside `ceil(log2(n+1)) - 1` = `floor(log2(n))`.*

## Heap:

**Definition:** A heap is a complete binary tree with the two properties:
* Structural property - all levels are full, except possibly the last one, which is filled from left to right
* Order Property for any node:
    * parent(x) >= x: Max heap (starts with the largest element)
    * parent(x) <= x: Min heap (start with the smallest element)
    * The order property only defines a child parent relationship, sibling parent nodes can be larger/smaller than the parents child node

Completeness nor binary tree or required to be considered a "heap". They just make the tree more efficient.

### Storing a tree in an Array:
* Root of a tree is `A[1]` <- stored like this so `2i` math works
* left child of `A[i] = A[2i]`
* right child of `A[i] = A[2i + 1]`
* parent of `A[i] = A[floor(i / 2)]`
* the heap size of A is less than or equal to the length of A

the reason complete binary trees are used is because in this scheme they will store the elements in the most compact configurations

You can store a tree as a link list but it requires way more memory because it requires three pointer for each node. 

Arrays also access elements faster than 

Max heapify is akin to making
We should write BUILD MAX HEAP

BUILD MAX HEAP is big O(nLog(n)), because it loops over a O(Log(n)) procedure n times
A tighter bound for BUILD MAX HEAP is O(n)

We should also write HEAP SORT

The way heap sort works is:
* Build a max heap from the array
* Swap the root (the Maximum element in the array) with the last element of the array
* Discard this last node by decreasing the heap size
* Reheapify on the elements of the array except those we have already sorted
* repeat

HEAP SORT works in O(nlog(n)) time

HEAP SORT is a good sorting algorithm but still not as good as quick sort. Quick Sort requires both less swaps and is stable

Stable again means that the sorting Algorithm... (maintains state I think)

Reheapify is what 

## Priority Queues:

Priority queues store its data as key value pairs. So that you establish "importance" as to what task should be processed next

Unlike queue where it is FIFO, priorities queues will always remove the highest priority item first

An example of a priority queue would be a schedule where tasks have associated times:
* 2:40p - Make Lunch
* 3:00p - Do Homework
* 3:10p - Cry

As we "pop" elements from the queue we remove them based on how how soon in time they are

`priorityQueue.pop(); <- returns "Make Lunch"`

When adding an element to the priority queue it will be placed in according to priority.
```
priorityQueue.push(3:05p, "give up")
/*List looks like:
    * 2:40p - Make Lunch
    * 3:00p - Do Homework
    * 3:05p - give up
    * 3:10p - Cry
*/
```

### Operations
* Insert(S,x) - insert element x into S
* ExtractMax(S) - remove and return element of S with largest key
* Maximum(S) - return element of S with largest key
* IncreaseKey(S, x, k) - increase value of element `x`'s key to `k` (assuming k >= x's current key)

*Note that for some implementations we will be extracting minimums rather than maximums.*

Time Complexity:
* MAX-HEAPIFY O(log n)
* BUILD-MAX-HEAP O(n)
* HEAP-SORT O(n log n)
* MAX-HEAP-INSERT O(log n)
* HEAP-EXTRACT-MAX O(log n)
* HEAP-INCREASE-KEY O(log n)
* HEAP-MAXIMUM O(1)



*Note you can do priority Queue using linked list but it won't be as fast :(*

## Problems:
We can't know where the second largest element in the heap because we only know 

* What is the maximum number of nodes in a max heap of height h?
    * 
* What is the maximum number of leaves?
    * ceil(n/2)
* What is the maximum number of internal nodes?
    * floor(n/2)
