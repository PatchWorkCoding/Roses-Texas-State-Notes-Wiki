# BTS (Binary Search Tree)

## Tree Traversal
How one navigates the tree

Pre-order traversal: 
```
Input x is the root of the subtree
PreOrderTraversal(x) {
    if (x != null) {
        output key(x);
        preOrderTraversal(Left);
        preOrderTraversal(Right);       
    }
}
```

Post-order traversal:
```
Input x is the root of the subtree
postOrderTraversal(x) {
    if (x != null) {
        postOrderTraverse(Left);
        postOrderTraverse(Right);
        output key(x);
    }
}
```
*The most useful one.*

In-order traversal:
```
InOrderTraversal(x) {
    if (x != null) {
        InOrderTraversal(Left);
        output key(x);
        InOrderTraversal(Right);
        
    }
}
```

## Binary search tree Property
*For every node X*
* All the keys in its left subtree are smaller than the key value in X
* All the keys in its right subtree are larger than the key value in X
* No duplicate keys are allowed

Binary search trees are stored using pointer representations meaning each node has a pointer to another node

Most binary search trees aren't complete so they can't be efficiently stored in an array 

There can be many different version of the same BTS because they don't need to be complete

## Search
Sudo Code
```
while (t != null){
    if: t == node->val
        return node;
    else if: t > node->val
        t = node->right
    else if: t < node->val
        t = node->left
}
```

In order traversal will print BTS in to a sorted array

### Insertion
First search for the value then if you don't find it add the node to where it would be

### Deletion
First search for a value if you find the node delete it. Then reattach its children to the tree

**Three cases for Node Deletion**
* If there are no children just delete the node.

* If there is only one child it is easy just swap the pointer `prevNode->left = node->left` for example

* If there is more than one child then:
    * Find the smallest value in the right subtree or find the largest element in the left subtree.
    * Replace the deleted node with the new node, and then delete the new node and repeat the deletion process

### FindMax/FindMin
* To find min, keep moving left until you encounter a null pointer
* To find max, keep moving right until you encounter a null pointer

## Balanced BST
since BST have time O(n) which is really to just too slow

There are many different version so BST:
* AVL
    * H= 
* Red-Black tree
* Splay tree
* B-tree

**Rotation:** Any extra operation done to a tree to make it balanced

### AVL
the AVL additional tree property:

For any node the height difference between left and right subtree is at most 1.
(i.e. from the root of the right subtree *Not including the root* what is the longest past to the node, same with the different)

AVL tree is more balanced but more memory intensive

### Red-Black Tree
Rules:
1. Every node is either read or black
2. The root is black
3. Every every leaf node is null and black
4. If a node is red both its children are black
5. for each node all paths from the node to descendant leaves contain the same number of black nodes

red black tree makes it balanced because longest path is at most double the length of the shortest past

Read black tree 

### Rotations

