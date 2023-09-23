#include <iostream>
#include <vector>

// problem: http://practice.geeksforgeeks.org/problems/leaders-in-an-array/0

void print_leaders(std::vector<int> const& vec) {

    std::vector<int> leaders; // accumulate leaders to print them in original order
    leaders.reserve(vec.size());
    int max = vec.back();
    leaders.push_back(max); // last element is always a leader
    for (auto it = vec.rbegin() + 1; it != vec.rend(); ++it) {
        if (*it >= max) {
            max = *it;
            leaders.push_back(max);
        }
    }

    for (auto it = leaders.rbegin(); it != leaders.rend(); ++it) {
        std::cout << *it << " ";
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
        print_leaders(vec);
        vec.clear();
    }

    return 0;
}
