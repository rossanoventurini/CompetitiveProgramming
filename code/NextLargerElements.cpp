#include <iostream>
#include <vector>

// problem: http://practice.geeksforgeeks.org/problems/next-larger-element/0

void print_next_larger_elements(std::vector<int> const& vec) {
    size_t n = vec.size();
    for (int i = 0; i < n; ++i) {
        int max = -1;
        for (int j = i; j < n; ++j) {
            if (vec[j] > vec[i]) {
                max = vec[j];
                break;
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
        std::cin >> n;
        vec.reserve(n);
        for (int j = 0; j < n; ++j) {
            int x = 0;
            std::cin >> x;
            vec.push_back(x);
        }
        print_next_larger_elements(vec);
        vec.clear();
    }

    return 0;
}
