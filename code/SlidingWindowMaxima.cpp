#include <iostream>
#include <vector>

// problem: http://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

void print_sliding_window_maxima(std::vector<int> const& vec, int k) {
    for (int i = 0; i < vec.size() - k + 1; ++i) {
        int max = vec[i];
        for (int j = 0; j < k; ++j) {
            if (vec[i + j] > max) {
                max = vec[i + j];
            }
        }
        std::cout << max << " ";
    }
    std::cout << std::endl;
}

int main() {

    int num_test_cases = 0;
    std::cin >> num_test_cases;

    std::vector<int> vec;
    for (int i = 0; i < num_test_cases; ++i) {
        int n = 0;
        int k = 0;
        std::cin >> n;
        std::cin >> k;
        vec.reserve(n);
        for (int j = 0; j < n; ++j) {
            int x = 0;
            std::cin >> x;
            vec.push_back(x);
        }
        print_sliding_window_maxima(vec, k);
        vec.clear();
    }

    return 0;
}
