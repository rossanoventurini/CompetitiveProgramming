#include <iostream>
#include <vector>
#include <stack>
#include <climits>

// problem: http://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst/0

int check_preorder(std::vector<int> const& visit) {

    int root = INT_MIN;
    std::stack<int> s;

    for (auto current: visit) {

        // we maintain the invariant
        // of being in a right subtree
        if (current < root) return 0;

        while (!s.empty()) { // find next greater
            if (current < s.top()) {
                s.pop();
            } else {
                root = s.top();
                break;
            }
        }

        // now current is next greater of root,
        // therefore we are in a right subtree
        s.push(current);
    }

    return 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int num_test_cases = 0;
    std::cin >> num_test_cases;

    std::vector<int> vec;
    for (int i = 0; i < num_test_cases; ++i) {
        int n = 0;
        std::cin >> n;
        vec.reserve(n);
        for (int j = 0; j < n; ++j) {
            int x = 0;
            std::cin >> x;
            vec.push_back(x);
        }

        std::cout << check_preorder(vec) << std::endl;
        vec.clear();
    }

    return 0;
}
