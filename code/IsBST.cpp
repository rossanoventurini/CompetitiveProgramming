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
std::pair<int,int> min_max_subtree(Node* root, bool* res) {
    bool l = true;
    bool r = true;
    int curr_min = root->data;
    int curr_max = root->data;

    if (root->left) {
        auto left = min_max_subtree(root->left, &l);
        if (left.second > root->data) l = false;
        curr_min = std::min(curr_min, left.first);
        curr_max = std::max(curr_max, left.second);
    }
    if (root->right) {
        auto right = min_max_subtree(root->right, &r);
        if (right.first < root->data) r = false;
        curr_min = std::min(curr_min, right.first);
        curr_max = std::max(curr_max, right.second);
    }

    *res = l&&r;
    return std::make_pair(curr_min, curr_max);
}

bool isBST(Node* root) {
    if(!root) return true;
    bool res = true;
    auto p = min_max_subtree(root, &res);
    return res;
}
