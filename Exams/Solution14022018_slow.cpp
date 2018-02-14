#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <cmath>

int main() {

    std::ios_base::sync_with_stdio(false);

    uint64_t n = 0; // number of elements in arrays
    std::cin >> n;

    typedef uint64_t int_type;

    std::vector<int_type> A;
    A.reserve(n);

    for (uint64_t i = 0; i < n; ++i) {
        int_type x = 0;
        std::cin >> x;
        A.push_back(x);
    }

    std::vector<int_type> L(n);
    std::vector<int_type> R(n);

    for (uint64_t i = 0; i < n-1; ++i)
        for (uint64_t j = i+1; j < n; ++j)
            if (A[i] < A[j]) {
                        R[i]++;
                        L[j]++;
                    }

    int_type count = 0;

    for (uint64_t i = 0; i < n; ++i)
        count += L[i]*R[i];

    std::cout << count << std::endl;

    std::cout << std::flush;
    // auto end = clock_type::now();
    // std::chrono::duration<double> elapsed = end - start;
    // std::cout << "queries executed in: " << elapsed.count()
    //           << " [sec]" << std::endl;

    return 0;
}
