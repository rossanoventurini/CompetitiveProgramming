#include <iostream>
#include <vector>
#include <string>
<<<<<<< HEAD
#include <cstring>   // for memmove

// problem: http://practice.geeksforgeeks.org/problems/largest-even-number/0

// assume digits span a consecutive range, i.e., [min_digit..min_digit + num_digits]
template<typename Digital, typename Digit>
void counting_sort(Digital& a, size_t n, int num_digits, Digit min_digit, bool reverse = false) {

    std::vector<uint64_t> counts(num_digits + 1, 0);
    for (size_t i = 0; i < n; ++i) {
        ++counts[a[i] - min_digit];
    }

    for (uint32_t i = 1; i <= num_digits; ++i) {
        counts[i] += counts[i - 1];
    }

    Digital temp;
    temp.resize(n);

    // could do this with bool tricks
    size_t offset = 0;
    int sign = 1;
    int b = -1;

    if (reverse) {
        offset = n;
        sign = -1;
        b = 0;
    }

    for (size_t i = 0; i < n; ++i) {
        temp[offset + sign * counts[a[i] - min_digit] + b] = std::move(a[i]);
        --counts[a[i] - min_digit];
    }

    std::move(temp.begin(), temp.end(), a.begin());
}

void largest_even_number(std::string& str) {
    // ASCII codes for '0' to '9' span a consecutive range ([48..57])
    bool reverse = true;
    counting_sort<std::string, char>(str, str.size(), 10, '0', reverse);
=======
#include <vector>

>>>>>>> 497079b31c292c3e96226b52579adf7ec0e9f901

// problem: http://practice.geeksforgeeks.org/problems/largest-even-number/0

int main() {

    int num_test_cases = 0;
    std::cin >> num_test_cases;

    std::string str;
    for (int i = 0; i < num_test_cases; ++i) {
        std::vector<uint32_t> occs(10,0);
        std::cin >> str;

        int min_even = 10;
        int min_odd = 11;
        for(auto &c : str) {
            int c_id = c - '0';
            occs[c_id]++;
        }

        for(int i = 8; i >= 0; i-=2)
            if(occs[i]>0) min_even = i;
        for(int i = 9; i >= 0; i-=2)
            if(occs[i]>0) min_odd = i;

        if(min_even > min_odd) occs[min_even]--;
        for(int i = 9; i >= 0; --i)
            for(int j = 0; j < occs[i]; ++j)
                std::cout << i;
        if(min_even > min_odd && min_even != 10) std::cout << min_even;

        std::cout << std::endl;
        str.clear();
    }

    return 0;
}
