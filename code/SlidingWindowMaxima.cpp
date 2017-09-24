#include <iostream>
#include <vector>
#include <deque>

// problem: http://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

template<typename T>
std::vector<T> sliding_window_maximum(std::vector<T> const& A, int k) {
    std::deque<int>  Q; // Q will store positions not values
    std::vector<T> maxs;
    maxs.reserve(A.size() - k + 1);

    for (int i = 0 ; i < A.size(); ++i) {
        // Removes from front elements which are no longer in the window
        while (!Q.empty() and Q.front() <= i - k) {
            Q.pop_front();
        }

        // Removes from back elements which are no longer useful, i.e., no greater than the current element
        while (!Q.empty() and A[i] >= A[Q.back()]) {
            Q.pop_back();
        }

        Q.push_back(i);

        if (i >= k - 1) {
            maxs.push_back(A[Q.front()]);
        }
    }

    return maxs;
}

int main() {
    std::ios_base::sync_with_stdio(false);

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

        auto res = sliding_window_maximum(vec, k);
        for (auto const& x: res) {
            std::cout << x << " ";
        }
        std::cout << std::endl;

        vec.clear();
    }

    return 0;
}
