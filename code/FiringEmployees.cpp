#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

// problem: http://practice.geeksforgeeks.org/problems/firing-employees/0

/* Marks the prime numbers up to n with Sieve of Eratosthenes http://www.geeksforgeeks.org/sieve-of-eratosthenes/ */
std::vector<bool> generate_primes(size_t n) {
    std::vector<bool> primes(n, true);
    for(uint64_t i = 2; i <= (uint64_t) sqrt(n); ++i) {
        if (primes[i]) {
            uint64_t isquare = i*i;
            for(uint64_t j = isquare; j < n; j+=i)
                primes[j] = false;
        }
    }

    return primes;
}

int num_fired_employees(std::vector<int> const& vec) {

    size_t n = vec.size();

    // save the position of employees' ranks in original array
    std::vector<std::vector<int>> positions(n + 1, std::vector<int>());
    for (int i = 0; i < n; ++i) {
        positions[vec[i]].push_back(i + 1);
    }

    std::vector<int> seniors(n + 1, 0);

    std::stack<int> s;

    // for each employee calculate the number of his/her seniors
    s.push(positions[0].front()); // position of Mr. Alfred
    for (int i = 0; i < n; ++i) {
        auto list = positions[s.top()];
        s.pop();
        for (auto pos: list) {
            seniors[pos] = 1 + seniors[vec[pos - 1]];
            s.push(pos);
        }
    }

    auto primes = generate_primes(2*(n+1));
    int fired_employees = 0;
    for (int i = 1; i <= n; ++i) {
        if (seniors[i] and primes[seniors[i] + i]) {
            ++fired_employees;
        }
    }

    return fired_employees;
}

int main() {
    std::ios_base::sync_with_stdio(false);

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

        std::cout << num_fired_employees(vec) << std::endl;
        vec.clear();
    }

    return 0;
}
