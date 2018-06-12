#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <cmath>
#include <algorithm>

int main() {

    std::ios_base::sync_with_stdio(false);

    uint64_t n = 0; // number of elements in arrays
    std::cin >> n;

    std::vector<uint64_t > A;
    A.reserve(n);

    for (uint64_t i = 0; i < n; ++i) {
        uint64_t  x = 0;
        std::cin >> x;
        A.push_back(x);
    }

    std::vector<uint64_t> L(n, 1);
    std::vector<uint64_t> R(n, 1);

    for(size_t i = 1; i < n; ++i) {
        if (A[i-1] < A[i])
            L[i] = L[i-1] + 1;
    }

    for(int32_t i = n-1; i >= 0; --i) {
        if (A[i] < A[i+1])
            R[i] = R[i+1] + 1;
    }

    uint64_t m = std::max(R[0], L[n-1]) + 1;

    for (uint64_t i = 1; i < n-1; ++i) {
        if (A[i-1] + 1 < A[i+1]) {
            uint64_t v = L[i-1] + R[i+1] + 1;
            m = std::max(v, m);
        }
        m = std::max(L[i] + 1, m);
        m = std::max(R[i] + 1, m);

    }
    std::cout << m << std::endl;

    std::cout << std::flush;

    return 0;
}
