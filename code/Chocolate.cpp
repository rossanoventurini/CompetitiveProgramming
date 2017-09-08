#include <iostream>
#include <vector>
#include <numeric>

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

  size_t n;
  cin >> n;
  
  auto v = get_input_sequence<uint32_t>(n);
  
  uint32_t sum = accumulate(v.begin(), v.end(), 0);  
  uint32_t prefix_sum = 0;
  size_t i = 0;  
  while(i < n and prefix_sum < sum) {
    sum -= v[i];
    prefix_sum += v[i];
    i++;
  }
  
  if(i != 0 and sum < prefix_sum - v[i-1]) i--; // who is going to eat i-th bar?
  
  cout << i << " " << n-i << endl;
  return 0;
}