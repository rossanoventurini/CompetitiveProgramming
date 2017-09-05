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
  
  size_t n; 
  cin >> n;
  auto length = get_input_sequence<int>(n);
  sort(length.begin(), length.end());
    
  size_t numTowers = 0, currentLength = 0, currentHeight = 0, maxHeight = 1;
  for(size_t k = 0; k < n; k++) {
    if(length[k] == currentLength) {
      currentHeight += 1; 
      if(currentHeight > maxHeight)
        maxHeight = currentHeight;
      } else {
        currentLength = length[k]; 
        currentHeight = 1; 
        numTowers++;
      }
  }    
  cout << maxHeight << " " << numTowers << endl;
  return 0;
} 
