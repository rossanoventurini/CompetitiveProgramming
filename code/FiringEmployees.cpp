#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

// problem: http://practice.geeksforgeeks.org/problems/firing-employees/0

bool is_prime(int x) {
    int n = (int) sqrt(x);
    for (int f = 2; f <= n; ++f) {
        if (x % f == 0) return false;
    }
    return true;
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

    int fired_employees = 0;
    for (int i = 1; i <= n; ++i) {
        if (seniors[i] and is_prime(seniors[i] + i)) {
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
