#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
  
  int n;
  cin >> n;
  auto a = get_input_sequence<int64_t>(n);
  auto c = vector<int64_t>(n, 0);
  
  int64_t S = 0;
  
  for(auto x : a)
    S +=x;
  
  if(S % 3 != 0) {
    cout << "0\n";
    return 0;
  }
  
  S /= 3;
  int64_t L = 0, counter = 0;
  for(int i = n-1; i >= 0; --i) {
    L += a[i];
    if(L == S)
      c[i] = 1;
  }
  
  for(int i = n-2; i >= 0; --i)
    c[i] += c[i+1];

  L = 0;  
  int64_t results = 0; 
  for(int i = 0; i < n-2; ++i) {
    L += a[i];
    if(L == S) results+=c[i+2];
  }
  
  cout << results << endl;
  
  return 0;
}