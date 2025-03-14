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

**Height** the longest path in a tree, The largest chain from the root to the furthest leaf node

Paths are counted by edges not nodes

**Depth/Level** the length of path from the root to a given node

**Height of a Node** the length of the path from the given node to the furthest leaf 


### Important Concepts!
**Full binary Tree** a binary tree where each node has *exactly* two children or no children.

**Complete Binary Tree** a binary tree where each level is full except for the leaf level. and the leaf level is "left adjusted" meaning all the longest chain of nodes is on the right side of the tree. The max number of a given depth is = 2^depth

**Perfect Binary Tree** A tree that is both a "Full Binary Tree" and a  "Complete Binary Tree"

"Completeness" is necessary feature for storing a tree structure in an array. which is the most efficient way of storing a tree.

**Equation Definitions of a Binary Tree:**
* At the level l there are at most 2^l nodes in a binary tree
* A binary tree with height d has at most (2^d+1) - 1 Nodes
* A binary tree with n Nodes has height at least floor(log^2(n))
* Height = floor(log^2(n))
* Nodes =  (2^height+1) - 1


## Heap:

**Definition:** A heap is a complete binary tree with the two properties:
* Structural property - all levels are full, except possibly the last one, which is filled from left to right
* Oder Property for any node:
    * parent(x) >= x: Max heap (starts with the largest element)
    * parent(x) <= x: Min heap (start with the smallest element)
    * The order property only defines a child parent relationship, sibling parent nodes can be smaller than the parents child node

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
