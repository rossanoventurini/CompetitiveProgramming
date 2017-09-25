#include <iostream>
#include <string>
#include <vector>


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
            if (!(c_id&1))  // c_id is even
                min_even = std::min(c_id, min_even);
            else
                min_odd = std::min(c_id, min_odd);
        }

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
