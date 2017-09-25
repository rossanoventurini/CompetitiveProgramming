/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node* left, * right;
}; */
/* Should return true if tree represented by root is BST.
   For example, return  value should be 1 for following tree.
         20
     /      \
   10       30
  and return value should be 0 for following tree.
         10
     /      \
   20       30 */


// problem: http://practice.geeksforgeeks.org/problems/check-for-bst/1

#include <climits> // for INT_MIN and INT_MAX

bool check(Node* root, int min, int max) {
    if (!root) return true; // root is a leaf
    if (root->data < min or root->data > max) return false;
    return check(root->left, min, root->data - 1) and
           check(root->right, root->data + 1, max);
}

bool isBST(Node* root) {
    return check(root, INT_MIN, INT_MAX);
}
