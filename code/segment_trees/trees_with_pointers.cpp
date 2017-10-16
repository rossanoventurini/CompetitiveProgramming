#include <iostream>
#include <vector>
#include <deque>
#include <chrono>

struct node {
    node(int k,
         node* l = nullptr,
         node* r = nullptr)
        : key(k), left(l), right(r)
    {}

    int key;
    node* left;
    node* right;
};

uint64_t sum(node* n) {

    if (n == nullptr) {
        return 0;
    }

    uint64_t left_subtree_sum = 0;
    if (n->left != nullptr) {
        left_subtree_sum = sum(n->left);
    }
    uint64_t right_subtree_sum = 0;
    if (n->right != nullptr) {
        right_subtree_sum = sum(n->right);
    }

    return n->key + left_subtree_sum + right_subtree_sum;
}

int main() {

    std::ios_base::sync_with_stdio(false);

    node* root = nullptr;
    typedef std::chrono::high_resolution_clock clock_type;

    auto start = clock_type::now();
    {
        std::deque<node*> q;
        int n = 0;
        std::cin >> n;

        for (int i = 0; i < n; ++i) {
            int x = 0;
            std::cin >> x;
            node* n = new node(x);
            q.push_back(n);
        }

        node* last = nullptr;
        if (n % 2) {
            last = q.back();
            q.pop_back();
        }

        // helper function
        auto min_parent = [&](node* left, node* right) {
            int min = std::min<int>(left->key, right->key);
            node* parent = new node(min, left, right);
            q.push_back(parent);
        };

        // build tree topology
        while (q.size() != 1) {
            min_parent(q[0], q[1]);
            q.pop_front();
            q.pop_front();
        }

        if (last != nullptr) { // create a new root node with
                               // the old root as left child
                               // and the last node as right child
            min_parent(q.front(), last);
            q.pop_front();
        }

        root = q.front();
    }
    auto end = clock_type::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "building took: " << elapsed.count() << " [sec]" << std::endl;

    start = clock_type::now();
    uint64_t s = sum(root);
    end = clock_type::now();
    elapsed = end - start;

    std::cout << "sum is: " << s << std::endl;
    std::cout << "sum took: " << elapsed.count() << " [sec]" << std::endl;

    return 0;
}
