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

        for(auto &c : str) {
            int c_id = c - '0';
            occs[c_id]++;
        }

        int min_even = 10;
        int min_odd = 11;
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
