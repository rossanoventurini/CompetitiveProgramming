#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
      cin >> sequence[i];
    return sequence;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  
  size_t n, q;
  cin >> n;
  cin >> q;
  auto array = get_input_sequence<int32_t>(n);
  
  vector<int32_t> F(n+1);
  
  int l, r;
  for(size_t i = 0; i < q; ++i) {
    cin >> l >> r;
    F[l-1] += 1;
    F[r] -= 1;
  }
  
  /* Prefix sums */
  for(size_t i = 1; i < n; ++i) 
    F[i] += F[i-1];
  
  sort(array.begin(), array.end());
  sort(F.begin(), F.end()-1);
  
  int64_t result = 0;
  for(size_t i = 0; i < n; ++i) 
    result += static_cast<int64_t>(F[i])*static_cast<int64_t>(array[i]);
  
  cout << result << endl; 
  
  return 0;
}
