#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
#include <cmath>

#define LEFT(i)     2 * i + 1
#define RIGHT(i)    2 * i + 2
#define PARENT(i) (i - 1) / 2

int main() {

    std::ios_base::sync_with_stdio(false);

    std::vector<int> tree;

    typedef std::chrono::high_resolution_clock clock_type;
    auto start = clock_type::now();

    {
        int n = 0;
        std::cin >> n;
        int tree_size = 2 * n - 1;
        tree.resize(tree_size);

        int h = ceil(log2(n));
         // left-most node id following level order
        int left_most_node = (int(1) << (h - 1)) - 1;
        int offset = LEFT(left_most_node);

        // set leaves circularly

        // 1. go forward
        int i = 0;
        for (int j = offset; j != tree_size; ++i, ++j) {
            int x = 0;
            std::cin >> x;
            tree[j] = x;
        }

        // 2. fall back
        for (int j = 0; i != n; ++i, ++j) {
            int x = 0;
            std::cin >> x;
            tree[n - 1 + j] = x;
        }

        // set internal nodes
        for (int i = tree_size - 1; i != 0; i -= 2) {
            int min = std::min<int>(tree[i], tree[i - 1]);
            tree[PARENT(i)] = min;
        }
    }

    auto end = clock_type::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "building took: " << elapsed.count() << " [sec]" << std::endl;

    start = clock_type::now();
    uint64_t s = std::accumulate(tree.begin(), tree.end(), uint64_t(0));
    end = clock_type::now();
    elapsed = end - start;

    std::cout << "sum is: " << s << std::endl;
    std::cout << "sum took: " << elapsed.count() << " [sec]" << std::endl;

    return 0;
}
