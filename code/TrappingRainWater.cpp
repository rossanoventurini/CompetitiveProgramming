#include <iostream>
#include <vector>
#include <cassert>

// problem: http://practice.geeksforgeeks.org/problems/trapping-rain-water/0

template<typename Iterator>
int trapped_rain_water(Iterator it, int& level) {
    if (*it > level) {
        level = *it;
    }
    int trapped_rain = level - *it;
    assert(trapped_rain >= 0);
    return trapped_rain;
}

void print_trapped_rain_water(std::vector<int> const& vec) {
    auto begin = vec.begin();
    auto end = vec.end() - 1;

    int tot_trapped_rain = 0;
    int level = 0;

    while (begin != end) {
        if (*begin <= *end) {
            tot_trapped_rain += trapped_rain_water(begin, level);
            ++begin;
        } else {
            tot_trapped_rain += trapped_rain_water(end, level);
            --end;
        }
    }

    std::cout << tot_trapped_rain << "\n";
};

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

        print_trapped_rain_water(vec);
        vec.clear();
    }

    return 0;
}
