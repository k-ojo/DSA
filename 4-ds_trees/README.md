# Tree

A tree is a non linear data structure that is usually used to store a hierarchical.

### Definition
A tree is a collection of entities called nodes linked together to simulate a hierarchy.

### Properties
Topmost node is called root. 

Each node may point to other nodes called children of the node. Children of same node are siblings. The node is a parent. A node without child is called leaf.

if A and B are nodes in tree and we can go from A to B, then A is an ancestor B. Also, B is descendent of A.

Depth of node is:
Number of edges in path from root to x.
Depth of root is 0.

Height of node
Number of edges in longest path to a leaf from node
height of leaf = 0.

Height of tree = height of root node.

Balanced binary tree is a binary tree for which the difference in height of both left and right trees of every node is less than a constant usually 1.

A perfect BT is the one whose height is the same regardless of the path taken. Every node has 0 or 2 children.

#### Binary Search Tree
A BT in which for each node, all the values at left are lower or equall and the values at right are greater.


## Abstract Data Type(ADT) and Implementation
The following are the basic operation of a tree ADT:

1. insert()
Deletes the current top and points assigns the top to the next node.

2. search()
Pushes new node to top of tree

3. delete()
checks if tree is empty

4. travers()

## APPLICATION

1. Processes
2. Printer 
