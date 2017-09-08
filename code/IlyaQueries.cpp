#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  
  string s;
  cin >> s;

  size_t n = s.length();  
  vector<uint32_t> sums(n+1);
  sums[0] = 0;
  for(size_t i = 1; i < n; ++i) { 
    sums[i] = s[i-1] == s[i] ? sums[i-1] + 1 : sums[i-1];
  }
  sums[n] = sums[n-1];
  
  size_t q;
  cin >> q;
  for(size_t i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    cout << sums[r-1]-sums[l-1] << endl;
  }
  
  return 0;
}