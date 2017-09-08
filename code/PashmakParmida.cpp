#include <iostream>
#include <vector>
#include <algorithm>
#include "fenwick_tree.hpp"

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

template<typename T> 
void remap(vector<T>& a) {
  vector<T> tmp(a.size());
  copy(a.begin(), a.end(), tmp.begin());
  sort(tmp.begin(), tmp.end());
  size_t sz = distance(tmp.begin(), unique(tmp.begin(), tmp.end()));
  tmp.resize(sz);
  
  for(auto &x : a)
    x = distance(tmp.begin(), lower_bound(tmp.begin(), tmp.end(), x));
}

int main() {
  size_t n;
  cin >> n;
  
  auto a = get_input_sequence<int>(n);
  remap<int>(a);
  
  fenwick_tree<int> f(n);
  vector<int> suffix_counter(n);
  vector<int> counter(n);
  
  for(int i = n-1; i >= 0; --i) {
    counter[a[i]]++;
    suffix_counter[i] = counter[a[i]]; // number occs a[i] in a[i..n-1]
    f.add(counter[a[i]], 1);
  }
  
  fill(counter.begin(), counter.end(), 0); 
   
  uint64_t res = 0;
  for(int i = 0; i < n; ++i) {
    f.add(suffix_counter[i], -1);
    counter[a[i]]++; // number occs a[i] in a[0..i]
    res += f.sum(counter[a[i]]-1);
  }
  
  cout << res << endl;
  return 0;
}