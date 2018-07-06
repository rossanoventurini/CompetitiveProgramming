#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

int main() {

    std::ios_base::sync_with_stdio(false);

    size_t h, w;
    std::cin >> h;
    std::cin >> w;

    std::vector<std::vector<uint64_t >> H(h+1);
    std::vector<std::vector<uint64_t >> V(h+1);

    for(size_t i = 0; i <= h; ++i) {
        H[i] = std::vector<uint64_t>(w+1,0);
        V[i] = std::vector<uint64_t>(w+1,0);
    }

    std::vector<std::string> rows(h);
    for(size_t i = 0; i < h; ++i)
        std::cin >> rows[i];

    for(size_t i = 0; i < h; ++i)
        for(size_t j = 0; j < w; ++j) {
            H[i+1][j+1] = H[i][j+1] + H[i+1][j] - H[i][j];
            V[i+1][j+1] = V[i][j+1] + V[i+1][j] - V[i][j];
            if(rows[i][j] == '#') continue;
            if(j != w - 1 && rows[i][j+1] == '.') H[i+1][j+1] = 1;
            if(i != h - 1 && rows[i+1][j] == '.') V[i+1][j+1] = 1;
        }
std::cout << std::endl;
    // Compute prefix sums in 2D matrices H and V
    for(size_t i = 0; i < h; ++i) {
        uint64_t r_sum_H = 0, r_sum_V = 0;
        for(size_t j = 0; j < w; ++j) {
            r_sum_H += H[i+1][j+1];
            H[i+1][j+1] = H[i][j+1] + r_sum_H;
            std::cout << H[i+1][j+1] << " ";
            r_sum_V += V[i+1][j+1];
            V[i+1][j+1] += V[i][j+1] + r_sum_V;
        }
        std::cout << std::endl;
}
    size_t q, r1, r2, c1, c2;
    std::cin >> q;
    std::cout << "q " << q << std::endl;
    for(size_t i = 0; i < q; ++i) {
        std::cin >> r1;
        std::cin >> c1;
        std::cin >> r2;
        std::cin >> c2;
        uint64_t ans = H[r2-1][c2] - H[r1][c2] - H[r2-1][c1] + H[r1][c1];
		ans += V[r2][c2-1] - V[r1][c2-1] - V[r2][c1] + V[r1][c1];
        std::cout << ans << std::endl;
    }

    std::cout << std::flush;

    return 0;
}
