#include <iostream>
#include <vector>

// problem: http://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

/*
    Property 1: the max-sum subarray cannot start with a negative number
                (the first element to the left of its beginning is negative),
                otherwise we could just remove its beninning and obtain a new
                subarray whose elements' sum is greater.

    Property 2: the sums of each prefix in the max-sum subarray must be positives,
                otherwise we could just remove the prefix of negative sum to obtain
                a new subarray whose elements' sum is greater.
*/
void print_max_sum_subarry(std::vector<int> const& vec) {
    int sum = vec.front(); // thus skip first element
    int max_sum = sum;

    for (auto it = vec.begin() + 1; it != vec.end(); ++it) {
        if (sum > 0) {
            sum += *it;
        } else {
            sum = *it;
        }

        if (sum > max_sum) {
            max_sum = sum;
        }
    }

    std::cout << max_sum << std::endl;
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
        print_max_sum_subarry(vec);
        vec.clear();
    }

    return 0;
}
