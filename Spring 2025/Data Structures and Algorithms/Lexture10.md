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