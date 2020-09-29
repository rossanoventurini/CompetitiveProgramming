#include <iostream>
#include <vector>
#include <stack>

// problem: http://practice.geeksforgeeks.org/problems/next-larger-element/0

struct int_type {

    int_type(int v)
        : val(v)
    {}

    void operator>>(int_type x) {
        std::cin >> x.val;
    }

    friend void operator>>(std::istream& in, int_type& x) {
        in >> x.val;
    }

    friend std::ostream& operator<<(std::ostream& out, int_type x) {
        out << x.val;
        return out;
    }

    static int_type invalid() {
        return int_type(-1);
    }

    int64_t val;
};

template<typename T, typename GreaterFunc>
std::vector<T> next_larger_elements(std::vector<T> const& vec, GreaterFunc g) {

    std::vector<T> results; // accumulate results here
    results.reserve(vec.size());

    std::stack<T> s;

    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        auto next_greater = T::invalid();
        while (!s.empty()) {
            auto tos = s.top();
            if (g(tos, *it)) {
                next_greater = tos;
                break;
            }
            s.pop();
        }
        results.push_back(next_greater);
        s.push(*it);
    }

    return results;
}

int main() {

    int num_test_cases = 0;
    std::cin >> num_test_cases;

    std::vector<int_type> vec;
    for (int i = 0; i < num_test_cases; ++i) {
        int n = 0;
        std::cin >> n;
        vec.reserve(n);
        for (int j = 0; j < n; ++j) {
            int_type x = 0;
            std::cin >> x;
            vec.push_back(x);
        }
        auto res = next_larger_elements(vec,
                       [](int_type x, int_type y) {
                           return x.val > y.val;
                       }
                   );

        for (auto it = res.rbegin();
                  it != res.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        vec.clear();
    }

    return 0;
}
