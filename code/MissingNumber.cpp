#include <iostream>

// problem: http://practice.geeksforgeeks.org/problems/missing-number-in-array/0

int main() {
    int num_test_cases = 0;
    std::cin >> num_test_cases;

    for (int i = 0; i < num_test_cases; ++i) {
        int n = 0;
        std::cin >> n;
        int sum = 0;
        int total_sum = n * (n + 1) / 2;
        for (int j = 0; j < n - 1; ++j) {
            int x = 0;
            std::cin >> x;
            sum += x;
        }
        std::cout << total_sum - sum << "\n";
    }

    return 0;
}
