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

bool isBST(Node* root) {

    if (!root) return true; // root is a leaf
    bool l = true;
    bool r = true;

    if (root->left) {
        Node* left = root->left;
        if ((root->data < left->data) or
            (left->right and left->right->data > root->data)) return false;
        l = isBST(root->left);
    }

    if (root->right) {
        Node* right = root->right;
        if ((root->data > right->data) or
            (right->left and right->left->data < root->data)) return false;
        r = isBST(root->right);
    }

    return l && r;
}
