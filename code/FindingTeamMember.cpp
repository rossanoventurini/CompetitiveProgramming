#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct team {
  size_t m1;
  size_t m2;
  int32_t strength;
  
  team(size_t a, size_t b, int64_t s) 
    : m1(a)
    , m2(b)
    , strength(s) {}
};

int main() {
  std::ios_base::sync_with_stdio(false);
  
  size_t n;
  cin >> n;
  
  vector<team> teams;
  teams.reserve(n*(n-1)/2);
  
  for(size_t i = 1; i < 2*n; ++i) {
    for(size_t j = 0; j < i; ++j) {
      int32_t strength;
      cin >> strength;
      teams.emplace_back(i, j, strength);
    }
  }
  
  sort(teams.begin(), 
       teams.end(),
       [](const team &a, const team &b) {
         return a.strength > b.strength;
       }
       );
   
  vector<size_t> assign(2*n); 
  for(auto &team: teams) {
    if(assign[team.m1] == 0 and assign[team.m2] == 0) {
      assign[team.m1] = team.m2 + 1; // +1, 0 is reserved to "no assigment yet"
      assign[team.m2] = team.m1 + 1; 
    }   
  }
  
  for(auto assigment: assign)
    cout << assigment << " ";
  cout << endl; 
  
  return 0;
}