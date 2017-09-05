#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>       /* sqrt */

using namespace std;

int main(){
  std::ios_base::sync_with_stdio(false);
  
  size_t n; 
  cin >> n;
  int pop;
  cin >> pop;
    
  vector<pair<double, uint64_t>> cities;
  cities.reserve(n);
    
  for(size_t i = 0; i < n; i++) {
    int x, y, population;
    cin >> x  >> y >> population;
    double distance = sqrt(x*x + y*y);
    cities.emplace_back(distance, population);
  }    
    
  sort(cities.begin(),
       cities.end(),
       [](const pair<double, uint64_t> & a, const pair<double, uint64_t> & b) {
            return a.first<b.first;
          }
  );
    
  for(auto &a : cities) {
    pop += a.second;
    if(pop >= 1000000) {
      cout.precision(8);
      cout << a.first << endl;
      return 0;
    }      
  }
    
  cout << -1 << endl;     
  return 0;
} 
