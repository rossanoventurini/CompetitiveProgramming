#include <iostream>
#include <string>
#include <algorithm> // for std::sort
#include <cstring>   // for memmove

// problem: http://practice.geeksforgeeks.org/problems/largest-even-number/0

void largest_even_number(std::string& str) {
    // ASCII codes for '0' to '9' span a consecutive range ([48..57])
    std::sort(str.begin(), str.end(),
        [](char x, char y) {
            return x > y;
        }
    );

    // determine the position of the smallest even number (if present)
    uint64_t i = str.size() - 1;
    while (str[i] % 2) {
        if (!i) break;
        --i;
    }

    if (str[i] % 2 == 0) { // could not contain any even number
        char x = str[i];
        // shift left by 1
        memmove(&str[i], &str[i + 1], str.size() - i - 1);
        str.back() = x;
    }
}

int main() {

    int num_test_cases = 0;
    std::cin >> num_test_cases;

    std::string str;
    for (int i = 0; i < num_test_cases; ++i) {
        std::cin >> str;
        largest_even_number(str);
        std::cout << str << std::endl;
        str.clear();
    }

    return 0;
}
