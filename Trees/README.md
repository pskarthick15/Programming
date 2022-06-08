### 3. Mirror Tree
Given a binary tree, the task is to create a new binary tree which is a mirror image of the given binary tree.

Examples: 

Inorder of original tree: 2 3 4 5 6 </br>
Inorder of mirror tree: 6 5 4 3 2 </br>
Mirror tree will be: </br>

Inorder of original tree: 12 1 2 8 9 </br>
Inorder of mirror tree: 9 8 2 1 12 </br>
- [Mirror tree](https://github.com/pskarthick15/Programming/blob/main/Trees/mirrortree.cpp)

### 4. Leftview

Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

<img src="https://github.com/pskarthick15/Programming/blob/main/Trees/screenshots/Screenshot%20(30).png" width="206" height="206"> </br>
- [Leftview](https://github.com/pskarthick15/Programming/blob/main/Trees/leftview.cpp)

### 5. Topview

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

<img src="https://github.com/pskarthick15/Programming/blob/main/Trees/screenshots/Screenshot%20(33).png" width="206" height="206"> </br>

Top view will be: 2 1 3
Note: Return nodes from leftmost node to rightmost node.
- [Topview](https://github.com/pskarthick15/Programming/blob/main/Trees/topview.cpp)

### 6. Sum tree

Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

<img src="https://github.com/pskarthick15/Programming/blob/main/Trees/screenshots/Screenshot%20(34).png" width="206" height="206"> </br>

Expected Time Complexity: O(N) </br>
Expected Auxiliary Space: O(height of tree) </br>
- [Sum tree](https://github.com/pskarthick15/Programming/blob/main/Trees/sumtree.cpp)

### Construct a tree and return its postorder given its inorder and preorder traversals

Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Example 1:

Input: </br>
N = 4 </br>
inorder[] = {1 6 8 7} </br>
preorder[] = {1 6 7 8} </br>
Output: 8 7 6 1 </br>

Example 2:

Input: </br>
N = 6 </br>
inorder[] = {3 1 4 0 5 2} </br>
preorder[] = {0 1 3 4 2 5} </br>
Output: 3 4 1 5 2 0
