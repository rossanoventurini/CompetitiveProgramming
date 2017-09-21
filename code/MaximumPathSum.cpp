/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
*/

int maxLeaf(struct Node *root, int *max) {
    if (root == NULL) return INT_MIN;
    int pathleft = maxLeaf(root->left, max);
    int pathright = maxLeaf(root->right, max);

    if ((pathleft == INT_MIN) && (pathright == INT_MIN)) return root->data;

    int pathcurr = root->data;
    pathcurr += pathleft > pathright ? pathleft : pathright;

    if ((pathleft != INT_MIN) && (pathright != INT_MIN)) {
        int maxcurr = root->data + pathleft + pathright;
        *max =  maxcurr > *max ? maxcurr : *max;
    }

    return pathcurr;
}


int maxPathSum(struct Node *root) {
 int max = INT_MIN;
 maxLeaf(root, &max);
 return max;
}
