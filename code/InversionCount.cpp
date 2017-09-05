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

uint64_t merge_and_count(vector<uint64_t>& A, size_t l, size_t middle, size_t r ) {
  size_t i = l;
  size_t j = middle + 1;
  vector<uint64_t> B((r-l)+1);
  size_t k = 0;
  uint64_t n_invs = 0;
  
  while((i <= middle) and (j <= r)) {
    if(A[i] < A[j]) {
      B[k++] = A[i++];
    } else {
      B[k++] = A[j++];
      n_invs += middle-i+1;
    }
  }
  
  while(i <= middle) {
    B[k++] = A[i++];
  }
  
  while(j <= r) {
    B[k++] = A[j++];
  }

  copy(B.begin(), B.end(), A.begin()+l);
  
  return n_invs;
}

/* Sort and count the number of invertions in A[l..r] */
uint64_t sort_and_count(vector<uint64_t>& A, size_t l, size_t r ) {
  if(l >= r) return 0;
  size_t middle = (l+r)/2;
  uint64_t l_count = sort_and_count(A, l, middle);
  uint64_t r_count = sort_and_count(A, middle + 1, r);  
  return l_count + r_count + merge_and_count(A, l, middle, r);
}


int main() {
  string blank;
  size_t n_tests;
  cin >> n_tests;
  getline(cin, blank);
  
  for(size_t i = 0; i < n_tests; ++i) {
    size_t n;
    cin >> n;
    auto A = get_input_sequence<uint64_t>(n);
    getline(cin, blank);
    uint64_t n_invs = sort_and_count(A, 0, n-1);
    
    cout << n_invs << endl;
  }
  
  return 0;
}